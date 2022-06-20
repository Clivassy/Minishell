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

    i = 0; 
    list = data->tokens_list;
    while(list)
    {
        if (list->type == T_HEREDOC)
        {
            printf("FOUND HEREDOC\n");
            while (i < 4)
            {
                ft_printf("> ");
                str = readline(str);
                i++;
            }
        }
        list = list->next;
    }
    return (0);
}