#include "minishell.h"

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