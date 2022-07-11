#include "minishell.h"

/*******************************************************************
Return error if :
Standard input is NOT from the terminal

*******************************************************************/


int main(int argc, char **argv, char **envp)
{
//	int	error_status;
	t_data	data;
	/*if (!isatty(0)) // check if the standar input is from a terminal
	{
		// message erreur + sortie
	}
	if (argc != 1)
    {
		// message erreur + sortie
	}*/
	ft_initialisation(&data, envp);
	// initialisation signaux
	//ft_minishell_loop(&data);
    ft_test_unset(&data, envp, argv);
    //ft_free_garbage_collector(&data);
	return (0);
}

/*
int main(int ac, char **av)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    ft_init_struct(data);
    if (ac == 1)
    {
        while (data->exit_asked == 1)
        {
           // ft_printf("minishell> ");
            // ici faire toutes les vérifs de l'input (isatty)
            data->read_line  = readline("minishell> ");
            // if PB on quitte proprement
            ft_minishell(data);
        }
    }
    else
        ft_lexer_error("Error: invalid number of args");
    ft_free_garbage_collector(data);
    return (0);
 // boucle infinie : lance le script
}

void    ft_pre_check_input(void)
{
    if (!isatty(0)) // check if the standar input is from a terminal
        ft_lexer_error("Error: standard input in not from a terminal");
}

void    ft_init_struct(t_data *data)
{
    //ft_initialisation(data);
    data->tokens_list = NULL;
    data->read_line = NULL;
    data->exit_asked = 1;
    data->gp_tokens_list = NULL;
    data->fd_lst = NULL;
    // ++
}*/
