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

void    ft_init_struct(t_data *input)
{
    input->read_line = NULL;
    input->command_list = (char**)malloc(10* sizeof(char*));
}

int main(int ac, char **av)
{
    t_data *input_minishell;

    int temp = -1;
    input_minishell = malloc(sizeof(t_data));
    ft_init_struct(input_minishell);
    ft_pre_check_input();
    if (ac == 1)
    {
        while (temp <= 0)
        {
            ft_printf("minishell>");
            // ici faire toutes les vérifs de l'input (isatty)
            input_minishell->read_line  = readline(input_minishell->read_line);
            temp++;
            // if PB on quitte proprement
            ft_minishell(input_minishell);
        }
    }
    else 
        ft_lexer_error("Error: invalid number of args");
    return (0);
 // boucle infinie : lance le script   
}