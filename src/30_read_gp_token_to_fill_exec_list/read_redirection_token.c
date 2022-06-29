#include "minishell.h"


//check pas fermetrue stdin
void	ft_set_exec_t_redirect_in(t_data *data, t_token *token, int process)
{
	// a faire : check fct avec partie excec fonctionnelle
	int	fd_infile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_infile = open(token->value, O_RDONLY); // verifier ces parametres
	if (fd_infile < 0)
		ft_exit(data); // erreur a gerer pour revenir dans boucle minishell
	if (ft_get_exec_elm(data->exec_list, process)->fd_in != 0)
		close(ft_get_exec_elm(data->exec_list, process)->fd_in);
	ft_get_exec_elm(data->exec_list, process)->fd_in = fd_infile;
}

// ajouter check pour pas fermer stdout
void	ft_set_exec_t_redirect_out(t_data *data, t_token *token, int process)
{
	// a faire : check fct avec partie excec fonctionnelle
	int	fd_outfile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_outfile = open(token->value, O_RDWR | O_CREAT | O_TRUNC, 0644); // verifier ces parametres
	if (fd_outfile < 0)
		ft_exit(data); // erreur a gerer pour revenir dans boucle minishell
	//write(fd_outfile,"test1",5);
	if (ft_get_exec_elm(data->exec_list, process)->fd_out != 1)
		close(ft_get_exec_elm(data->exec_list, process)->fd_out);
	ft_get_exec_elm(data->exec_list, process)->fd_out = fd_outfile;
}

// ajouter check pour pas fermer stdout
void	ft_set_exec_d_redirect_out(t_data *data, t_token *token, int process)
{
	// a faire : check fct avec partieC excec fonctionnelle
	int	fd_outfile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_outfile = open(token->value, O_RDWR | O_APPEND, 0644); // verifier ces parametres
	if (fd_outfile < 0)
		ft_exit(data); // erreur a gerer pour revenir dans boucle minishell
	//write(fd_outfile,"test2",5);
	if (ft_get_exec_elm(data->exec_list, process)->fd_out != 1)
		close(ft_get_exec_elm(data->exec_list, process)->fd_out);
	ft_get_exec_elm(data->exec_list, process)->fd_out = fd_outfile;
}
