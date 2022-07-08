#include "minishell.h"

// get cmd
// exec

int	ft_get_cmd(t_data *data)
{
	int	error_status_parser;

	error_status_parser = ft_lexer(data);
	error_status_parser = ft_parser(data); // ajouter empty list fct dans parser + heredoc?
	if (error_status_parser != 0)
		ft_print_error(data, error_status_parser);
	else
	{
		ft_group_tokens(data);
		ft_build_exec_list(data);
	}
	return (0);
}

void	ft_minishell_loop(t_data *data)
{
	int	error_status;

	error_status = 0;
        while (data->exit_asked != 1)
        {
			ft_handle_signals();
            data->read_line = readline("minishell> "); // ajouter secu fct
			ft_add_to_garbage_collector(data, data->read_line);
			if (data->read_line == NULL)
				ft_handle_ctrld(data);
			if (data->read_line[0] != 0)
				add_history(data->read_line);
			error_status = ft_get_cmd(data);
			if (error_status != 0)
				ft_print_error(data, error_status);
			else
			{
			ft_exec_elm_lst_print(data->exec_list);
			ft_exec_all_cmds(data);

			}
		ft_reinitialisation_read_data(data);
        }
	// faire fonction de free intermediaire + reinit de readline et data comme au debut
}
