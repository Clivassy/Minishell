#include "minishell.h"

/*----------------------------- PARSER ------------------------------

3 ) Parsing : lecture analyse des morceaux de phrase stockés dans ma listes chainée de tokens :
-> on va stocker chaque commande dans un char** de notre liste chainée (data ? ou exec?).
(chaque potentielle cmd étant délimitée par un pipe)

- parser : chevron obligatoirement succedé d'un mot (> MOT) 
pipe : nptk apres sauf autre pipe ou rien.

- Gestions des doubles redirect
----------------------------------------------------------------------*/

int ft_is_redirect_err(t_token *token)
{
    if (token->type == T_REDIRECT_IN || token->type == T_REDIRECT_OUT
        || token->type == D_REDIRECT_OUT)
        return (1);
    return(0);
}

int ft_redirect_errors(t_token *token)
{
    while (token)
    {
        if (ft_is_redirect_err(token))
        {
            if (!token->next)
                ft_lexer_error("Error: nothing after redirect");
            if (token->next->type == T_SPACE)
            {
                if (!token->next->next)
                    ft_lexer_error("ERROR 3");
                if (token->next->next->type != T_WORD)
                    ft_lexer_error("ERROR 2");
            }
            if (token->next->type != T_SPACE)
            {
                if(token->next->type != T_WORD)
                    ft_lexer_error("ERROR 4");
            }
        }
        token = token->next;
    }
   // printf("NO REDIRECT ERRORS\n");*/
    return (0);
}

int ft_is_empy_pipe(t_token *token)
{
    if (!token->next && token->type != T_WORD)
        ft_lexer_error("Error 5 : no word after last pipe");
    while (token->type != T_PIPE)
    {
        if (token->type == T_WORD)
            return(1);
        token = token->next;
    }
    return (0);
}

int ft_pipe_errors(t_token *token)
{
    //printf("first token is : %d\n", token->type);
    while (token)
    {
        if (token->type == T_PIPE)
        {
            if (!token->next)
                ft_lexer_error("Error 2 : pipe at the end");
            if (token->next->type == T_PIPE)
                ft_lexer_error("Error 3 : multiple pipes ");
            if (token->next->type != T_WORD)
            {
                if (token->next->type != T_SPACE)
            } 
                && token->next->next->type == T_SPACE)
                {
                    if (!token->next->next->next)
                        ft_lexer_error("Error : space and nothing after last redirect");
                }
            token = token->next;
            if (ft_is_empy_pipe(token) == 0 )
                ft_lexer_error("Error 4: no word found");
        }
        token = token->next;
    }
   // printf("NO PIPE ERRORS\n");
    return(0);
}

int ft_parser(t_data *data)
{
    t_token *list;

    list = data->tokens_list;
    if (list->type == T_PIPE)
        ft_lexer_error("Error 1 : pipe at the begining");
    ft_pipe_errors(list);
    ft_redirect_errors(list);
    return (0);
}



/* SAVE 

int ft_pipe_errors(t_token *token)
{
    //printf("first token is : %d\n", token->type);
    while (token)
    {
        if (token->type == T_PIPE)
        {
            if (!token->next)
                ft_lexer_error("Error 2 : pipe at the end");
            if (token->next->type != T_WORD && token->next->type != T_SPACE
                && token->next->next->type == T_SPACE)
                {
                    if (!token->next->next->next)
                        ft_lexer_error("Error : space and nothing after last redirect");
                }
            if (token->next->type == T_PIPE)
                ft_lexer_error("Error 3 : multiple pipes ");
            token = token->next;
            if (ft_is_empy_pipe(token) == 0 )
                ft_lexer_error("Error 4: no word found");
        }
        token = token->next;
    }
   // printf("NO PIPE ERRORS\n");
    return(0);
}

int ft_redirect_errors(t_token *token)
{
    while (token)
    {
        if (ft_is_redirect_err(token))
        {
            if (!token->next)
                ft_lexer_error("Error 5: nothing after redirect");
            if (token->next->type == T_WORD)
            {
                if (!token->next->next)
                    return(0);
            }
            if (!token->next->next && token->next->type != T_WORD)
                ft_lexer_error("Error 6: no word after redirect");
            if (token->next->next->type != T_WORD)
                ft_lexer_error("Error 7: multiples redirect");
            }
        token = token->next;
    }
   // printf("NO REDIRECT ERRORS\n");
    return (0);
}

*/