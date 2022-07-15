#include "minishell.h"

void	ft_stock_heredoc(int fd[2], int exp, t_data *data, char *heretag)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = ft_strdup("");
	ft_add_to_garbage_collector(data, tmp);
	while (1)
	{
		ft_handle_heredoc_signal();
		str = readline("> ");
		ft_add_to_garbage_collector(data, str);
		if (str == NULL)
			ft_handle_ctrld_heredoc(data, heretag);
		if (ft_strcmp(str, heretag) == 0)
			break ;
		if (exp > 0 && ft_is_expand_required(str))
			ft_expand_str(data, &str);
		write(fd[1], str, ft_strlen(str));
		write(fd[1], "\n", 1);
	}
}

void	ft_read_heredoc(int fd[2], t_data *data, char *heretag)
{
	int		expand;
	char	*here_tag;

	here_tag = heretag;
	expand = 0;
	if (ft_is_quoted(heretag))
		expand = 1;
	ft_rm_quotes_in_str(data, &here_tag);
	ft_stock_heredoc(fd, expand, data, here_tag);
	ft_exit2(data, 0);
}

int	ft_heredoc(t_data *data, t_token *heredoc_tkn)
{
	int				id;
	int				file[2];
	t_fd_heredoc	*fd_list;

	fd_list = NULL;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (pipe(file) == -1)
		ft_exit(data);
	fd_list = ft_new_fd(data, file[0]);
	ft_lstadd_back_fd(&data->fd_lst, fd_list);
	id = fork();
	if (id == -1)
		ft_exit(data);
	if (id == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_read_heredoc(file, data, heredoc_tkn->value);
	}
	if (close(file[1]) == -1)
		ft_exit_close_error(data);
	ft_wait_pid_heredoc(id, data);
	if (data->last_pipeline_exit_status == EXIT_CODE_CTRLC_HEREDOC)
		return (EXIT_CODE_CTRLC_HEREDOC);
	return (0);
}
