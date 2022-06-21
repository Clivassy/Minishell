#include "minishell.h"
/*----------------------------- PARSER ------------------------------
Gestion des heredocs + erreurs de syntaxe de heredocs 
// realine pour recuperer tout ce qui vient jusqu'au EOF  
- stocké dans un pipe.
- j'expand ce qui est a l'intérieur si jamais il y a des variables d'emvironnement
- ?? 
----------------------------------------------------------------------*/

int ft_read_heredoc(t_data *data)
{
    t_token *list;
    int i;
    char *str;
    
    str = NULL;
    i = 0; 
    list = data->tokens_list;
    while(list)
    {
        if (list->type == T_HEREDOC)
        {
            // tant qu'on arrive pas au delimiteur
            printf("FOUND HEREDOC\n");
            ft_printf("> ");
            str = readline(str);
        }
        list = list->next;
    }
    printf("STRING = %s\n", str);
    return (0);
}