#include "minishell.h"
void	ft_fill_exec_list_heredoc(t_data *data)
{
	int	process;
	t_token *pt_token;

	// boucle heredoc
	process = 0;
	pt_token = data->gp_tokens_list;
	while (pt_token)
	{
		if (pt_token->type == T_PIPE)
			process++;
		else if (pt_token->type == T_HEREDOC)
		{
			ft_set_exec_with_t_heredoc(data, pt_token, process);
		}
		pt_token = pt_token->next;
	}
}

void	ft_fill_exec_list_cmd__and_redirect(t_data *data)
{
	int	process;
	t_token *pt_token;

	// boucle cmd et redirection
	process = 0;
	pt_token = data->gp_tokens_list;
	while (pt_token)
	{
		if (pt_token->type == T_PIPE)
			process++;
		if (pt_token->type == T_CMD)
		{
			ft_set_exec_with_t_cmd_token(data, pt_token, process);
		}
		else if (pt_token->type == T_REDIRECT_IN)
		{
			ft_set_exec_t_redirect_in(data, pt_token, process);

		}
		else if (pt_token->type == T_REDIRECT_OUT)
		{
			ft_set_exec_t_redirect_out(data, pt_token, process);
		}
		else if (pt_token->type == D_REDIRECT_OUT)
		{
			ft_set_exec_d_redirect_out(data, pt_token, process);
		}
		pt_token = pt_token->next;
	}
}

void	ft_fill_exec_list(t_data *data)
{
	ft_create_exec_elm_list(data);
	ft_fill_exec_list_heredoc(data);
	ft_fill_exec_list_cmd__and_redirect(data);


}
