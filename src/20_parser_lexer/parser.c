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
int ft_pipe_errors(t_token *token)
{
    t_token *temp; 

    temp = token;
    printf("first token is : %d\n", token->type);
    while (token != NULL)
    {
        if (token->type == T_PIPE)
        {
            if (token->type == T_PIPE && !token->next)
                ft_lexer_error("Error 2 : pipe at the end");
            token = token->next;
            while (token->type != T_PIPE)
            {
                if (token->type == T_PIPE && token->next->type == T_PIPE)
                    ft_lexer_error("Error 3 : multiple pipes ");
                if (token->type == )
            }
        } 
        token = token->next;
    }
    printf("NO PIPE ERRORS\n");
    return(0);
}

int ft_parser(t_data *data)
{
    int i;
    t_token *list;

    list = data->tokens_list;
    if (list->type == T_PIPE)
        ft_lexer_error("Error 1 : pipe at the begining");
    ft_pipe_errors(list);
    return (0);
}