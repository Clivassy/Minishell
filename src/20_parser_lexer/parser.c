#include "minishell.h"

/*----------------------------- PARSER ------------------------------

3 ) Parsing : lecture analyse des morceaux de phrase stockés dans ma listes chainée de tokens :
-> on va stocker chaque commande dans un char** de notre liste chainée (data ? ou exec?).
(chaque potentielle cmd étant délimitée par un pipe)
-> dans 
----------------------------------------------------------------------*/


        
/*--------------------------------------------------------------------------

NB : On part du principe que j'ai extrait le pipe suivant chaque commande 
une commande == ce qui ce situe avant un pipe 
structure de commande ok : 
[heredoc][word][heredoc]
[word][redirect][word][$][word] 

-------------------------------------------------------------------------- 

structure incorrecte :

[pipe][word][redirect]
[space] [redirect]
[space]
[redirect]
[word] [D_redirect_out] [redirect_in]
[heredoc][heredoc]

--------------------------------------------------------------------------*/
int ft_pipe_errors(t_data *data)
{   
    t_token *head;

    head = data->tokens_list->next;
    printf("token = %d\n", head->type);
    if (head->type == T_PIPE)
            ft_lexer_error("Error 2");
    printf("NO PIPE ERRORS\n");
    return(0);
}

int ft_parser(t_data *data)
{
    int i;
    printf("OK\n");
    i = 0;
    if (data->tokens_list->type == T_PIPE)
            ft_lexer_error("Error 1");
    while (data->tokens_list != NULL)
    {
        if (data->tokens_list->type == T_PIPE)
        {
            ft_pipe_errors(data);
            printf("INPUT OK\n");
            return(0);
        }
        data->tokens_list++;
    }
    printf("OK\n");
    return (0);
}