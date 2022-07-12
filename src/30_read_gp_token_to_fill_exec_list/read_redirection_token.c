#include "minishell.h"

int	ft_set_exec_t_redirect_in(t_data *data, t_token *token, int process)
{
	int	fd_infile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_infile = open(token->value, O_RDONLY); // verifier ces parametres
	if (fd_infile < 0)
	{
		ft_print_open_error(data, token->value);
		return(1);
	}
	if (ft_get_exec_elm(data->exec_list, process)->fd_in != 0)
	{
		if(close(ft_get_exec_elm(data->exec_list, process)->fd_in) == -1)
			ft_exit_close_error(data);
	}
	ft_get_exec_elm(data->exec_list, process)->fd_in = fd_infile;
	return(0);
}

int	ft_set_exec_t_redirect_out(t_data *data, t_token *token, int process)
{
	// a faire : check fct avec partie excec fonctionnelle
	int	fd_outfile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_outfile = open(token->value, O_RDWR | O_CREAT | O_TRUNC, 0644); // verifier ces parametres
	if (fd_outfile < 0)
	{
		ft_print_open_error(data, token->value);
		return(1);
	}
	if (ft_get_exec_elm(data->exec_list, process)->fd_out != 1)
	{
		if(close(ft_get_exec_elm(data->exec_list, process)->fd_out) == -1)
			ft_exit_close_error(data);
	}
	ft_get_exec_elm(data->exec_list, process)->fd_out = fd_outfile;
	return(0);
}

int	ft_set_exec_d_redirect_out(t_data *data, t_token *token, int process)
{
	int	fd_outfile;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	fd_outfile = open(token->value, O_RDWR | O_CREAT | O_APPEND, 0644); // verifier ces parametres
	if (fd_outfile < 0)
	{
		ft_print_open_error(data, token->value);
		return(1);
	}
	if (ft_get_exec_elm(data->exec_list, process)->fd_out != 1)
		{
		if(close(ft_get_exec_elm(data->exec_list, process)->fd_out) == -1)
			ft_exit_close_error(data);
		}
	ft_get_exec_elm(data->exec_list, process)->fd_out = fd_outfile;
	return(0);
}

int	ft_set_exec_t_redirect_token(t_data *data, t_token *token, int process)
{
	if (token->type == T_REDIRECT_IN)
	{
		if(ft_set_exec_t_redirect_in(data, token, process) == 1)
		{
			return (1);
		}

	}
	else if (token->type == T_REDIRECT_OUT)
	{
		if(ft_set_exec_t_redirect_out(data, token, process) == 1)
		{
			return (1);
		}
	}
	else if (token->type == D_REDIRECT_OUT)
	{
		if(ft_set_exec_d_redirect_out(data, token, process) == 1)
		{
			return (1);
		}
	}
	return (0);
}
