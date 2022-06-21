#include "minishell.h"
/*----------------------------- PARSER ------------------------------
Gestion des heredocs + erreurs de syntaxe de heredocs 
// realine pour recuperer tout ce qui vient jusqu'au EOF  
- stocké dans un pipe.
- j'expand ce qui est a l'intérieur si jamais il y a des variables d'emvironnement
- ?? 
----------------------------------------------------------------------*/

/*
int ft_search_here_tag(t_data *data)
{

}*/

int ft_read_heredoc(t_data *data)
{
    t_token *list;
    char *str;
    int i = 1;
    char *here_tag = malloc(sizeof(char*) * 100);
    
    str = 0;
    list = data->tokens_list;
    while(list)
    {
        if (list->type == T_HEREDOC)
        {
            if (i == 1)
            {
                here_tag = list->next->next->value;
                i = 0;
            }
           printf("VALUE = %s\n", list->next->next->value);
            while (1)
            {
                ft_printf("> ");
                str = readline(NULL);
                if (strcmp(str, here_tag) == 0)
                {
                    if (!list->next->next)
                        ft_lexer_error("Error: no delimiter after heredoc");
                    return(0);
                }

            // tant qu'on arrive pas au delimiteur
            }
        }
        list = list->next;
    }
 //   printf("STRING = %s\n", str);
    return (0);
}