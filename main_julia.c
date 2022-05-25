#include "minishell.h"

int main(int ac, char **av)
{
    char *ptr = NULL;
    int temp = -1;

    ft_pre_check_input();
    if (ac == 1)
    {
        while (temp <= 0)
        {
            ft_printf("minishell>");
            ptr = readline(ptr);
            ft_search_quotes(ptr);
            temp++;
        }
    }
    else 
        ft_lexer_error("Error: invalid number of args");
    return (0);
 // boucle infinie : lance le script   
}