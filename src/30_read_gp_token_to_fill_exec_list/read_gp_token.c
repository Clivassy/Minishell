#include "minishell.h"

// fonctions en cours et non fonctionnelles

void	ft_set_exec_with_t_cmd_token(t_data *data, int process)
{

}

//check pas fermetrue stdin
void	ft_set_exec_t_redirect_in(t_data *data, t_token *token, int process)
{
	int	fd_infile;
	ft_printf("open file %s\n", token->value);

	fd_infile = open(token->value, O_RDONLY); // verifier ces parametres
	ft_printf("fd file: %d\n", fd_infile);

	if (fd_infile < 0)
		ft_exit(data); // erreur a gerer pour revenir dans boucle minishell
	if (ft_get_exec_elm(data->exec_list, process)->fd_in != 0)
		close(ft_get_exec_elm(data->exec_list, process)->fd_in);
	ft_get_exec_elm(data->exec_list, process)->fd_in  = fd_infile;
}

// ajouter check pour pas fermer stdout
void	ft_set_exec_t_redirect_out(t_data *data, t_token *token, int process)
{
	int	fd_outfile;

	ft_printf("open file out %s\n", token->value);
	fd_outfile = open(token->value, O_RDWR | O_CREAT | O_TRUNC, 0644); // verifier ces parametres
	ft_printf("fd file out: %d\n", fd_outfile);
	if (fd_outfile < 0)
		ft_exit(data); // erreur a gerer pour revenir dans boucle minishell

	write(fd_outfile,"test",4);
	if (ft_get_exec_elm(data->exec_list, process)->fd_out != 1)
		close(ft_get_exec_elm(data->exec_list, process)->fd_out);
	ft_get_exec_elm(data->exec_list, process)->fd_out = fd_outfile;
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
			//pt_token->value = NULL;

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

		}
		pt_token = pt_token->next;
	}
}
