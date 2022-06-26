#include "minishell.h"

// fonctions en cours et non fonctionnelles

void	ft_set_exec_with_t_cmd_token(t_data *data, int process)
{

}

void	ft_set_exec_t_redirect_in(t_data *data, t_token *token, int process)
{
	int	fd_infile;

	fd_infile = open(token->value, O_RDONLY);
	if (fd_infile < 0)
		ft_exit(data); // erreur a gerer pour revenir dans boucle
	ft_get_exec_elm(data->exec_list, process)->fd_in  = fd_infile;
}


void	ft_fill_exec_list(t_data *data)
{
	// parcours liste token 1
		// si heredoc > appel fct heredoc
		// MAJ redirection
	int	process;
	t_token *pt_token;

	// boucle heredoc
	//process = 0;
	//t_gp_token = data->gp_token;
	//while (pt_token)
	//{
	//	if (pt_token->type == T_PIPE)
	//		process++;
	//	else if (pt_token->type == T_HEREDOC)
	//	{
	//	}
	//	pt_token = pt_token->next;
	//}

	// boucle cmd et redirection
	process = 0;
	pt_token = data->gp_tokens_list;
	while (pt_token)
	{
		ft_printf("lecture sur process %d\n", process);
		if (pt_token->type == T_PIPE)
			process++;
		if (pt_token->type == T_CMD)
		{
			pt_token->value = NULL;

		}
		else if (pt_token->type == T_REDIRECT_IN)
		{

		}
		else if (pt_token->type == T_REDIRECT_OUT)
		{

		}
		else if (pt_token->type == D_REDIRECT_OUT)
		{

		}
		pt_token = pt_token->next;
	}
}
