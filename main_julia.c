#include "minishell.h"

/*******************************************************************
Return error if :
Standard input is NOT from the terminal

*******************************************************************/

int main(int argc, char **argv, char **envp)
{
    int	error_status;
	t_data	data;
	if (!isatty(0)) // check if the standar input is from a terminal
	{
		// message erreur + sortie
	}
	if (argc != 1)
    {
		// message erreur + sortie
	}
	ft_initialisation(&data, envp);
	ft_minishell_loop(&data);
    ft_free_garbage_collector(&data);
	return (0);
}