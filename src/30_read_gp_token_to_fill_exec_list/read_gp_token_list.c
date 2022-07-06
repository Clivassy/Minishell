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
	t_exec_elm	*exec_elm;

	// boucle cmd et redirection
	process = 0;
	pt_token = data->gp_tokens_list;
	while (pt_token)
	{
		if (pt_token->type == T_PIPE)
			process++;
		exec_elm = ft_get_exec_elm(data->exec_list, process);
		//ft_printf("process: %d\n", process);
		if (exec_elm->has_redirect_pb != 1)
		{
			if (pt_token->type == T_CMD)
			{
				ft_set_exec_with_t_cmd_token(data, pt_token, process);
			}
			else if (pt_token->type == T_REDIRECT_IN || pt_token->type == T_REDIRECT_OUT ||
				pt_token->type == D_REDIRECT_OUT)
			{
				if(ft_set_exec_t_redirect_token(data, pt_token, process) == 1)
				{
					exec_elm->has_redirect_pb = 1;
				}

			}
		}
		//else if (pt_token->type == T_REDIRECT_IN)
		//{(t_data *data, t_token *token, int process)edirect_in(data, pt_token, process);

		//}
		//else if (pt_token->type == T_REDIRECT_OUT)
		//{
		//	ft_set_exec_t_redirect_out(data, pt_token, process);
		//}
		//else if (pt_token->type == D_REDIRECT_OUT)
		//{
		//	ft_set_exec_d_redirect_out(data, pt_token, process);
		//}
		// ajouter HEREDOC ICI avec lecture liste chainee Julia
		pt_token = pt_token->next;
	}
}

void	ft_build_exec_list(t_data *data)
{
	ft_create_exec_elm_list(data);
	ft_fill_exec_list_heredoc(data);
	ft_fill_exec_list_cmd__and_redirect(data);


}
