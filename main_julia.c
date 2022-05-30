#include "minishell.h"

/*******************************************************************
Return error if : 
Standard input is NOT from the terminal 

*******************************************************************/
void    ft_pre_check_input(void)
{
    if (!isatty(0)) // check if the standar input is from a terminal
        ft_lexer_error("Error: standard input in not from a terminal");
}

void    ft_init_struct(t_data *input_minishell)
{
    input_minishell->read_line = NULL;
    input_minishell->exit_asked = 1;
    // ++ 
}

int main(int ac, char **av)
{
    t_data *input_minishell;

    input_minishell = malloc(sizeof(t_data));
    ft_init_struct(input_minishell);
    if (ac == 1)
    {
        while (input_minishell->exit_asked == 1)
        {
            ft_printf("minishell> ");
            // ici faire toutes les vérifs de l'input (isatty)
            input_minishell->read_line  = readline(input_minishell->read_line);
            // if PB on quitte proprement
            ft_minishell(input_minishell);
        }
    }
    else 
        ft_lexer_error("Error: invalid number of args");
    return (0);
 // boucle infinie : lance le script   
}