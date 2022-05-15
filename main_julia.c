#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>



/* Check if there are quotes */
void ft_search_quotes(char *str)
{   
    if (ft_strchr(str, '"') || ft_strchr(str, '\''))
        ft_printf("String contains dquote or squote");
    else
        ft_printf("String no contains quote");
    exit(EXIT_FAILURE);
}

/*Fonction qui va initialiserla structure */

// EXEC 
int main(int ac, char **av)
{
    char *ptr = NULL;
    int temp = -1;
    while (temp <= 0)
    {
        ft_printf("minishell>");
        ptr = readline(ptr);
        ft_search_quotes(ptr);
        temp++;
    }
    return (0);
 // boucle infinie : lance le script   
}