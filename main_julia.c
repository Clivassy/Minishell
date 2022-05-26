#include "minishell.h"

void    ft_init_struct(t_data *input)
{
    input->read_line = NULL;
    input->command_list = (char**)malloc(10* sizeof(char*));
}

int main(int ac, char **av)
{

    t_data *input;

    int temp = -1;
    input = malloc(sizeof(t_data));
    ft_init_struct(input);
    ft_pre_check_input();
    if (ac == 1)
    {
        while (temp <= 0)
        {
            ft_printf("minishell>");
            input->read_line  = readline(input->read_line );
            //ft_search_quotes(input->read_line );
            ft_parse_quote(input);
            temp++;
        }
    }
    else 
        ft_lexer_error("Error: invalid number of args");
    return (0);
 // boucle infinie : lance le script   
}