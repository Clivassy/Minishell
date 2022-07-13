#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	int	error_status;
	t_data	data;
	if (!isatty(0)) // check if the standar input is from a terminal
	{
		ft_printf("error: bad standard input\n");
		return(0);
	}

	if (argc != 1)
    {
		ft_printf("error: invalid number of arguments\n");
		return(0);	
	}
	ft_initialisation(&data, envp);
	ft_minishell_loop(&data);
    ft_free_garbage_collector(&data);
	return (0);
}
