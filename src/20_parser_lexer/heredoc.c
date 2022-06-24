#include "minishell.h"
/*----------------------------- PARSER ------------------------------
Gestion des heredocs + erreurs de syntaxe de heredocs 
// realine pour recuperer tout ce qui vient jusqu'au EOF  
- stocké dans un pipe.
- j'expand ce qui est a l'intérieur si jamais il y a des variables d'emvironnement
- ?? 
----------------------------------------------------------------------*/


// ++ft_strcmp

char   *ft_found_heretag(t_data *data, t_token *list)
{
    char *here_tag;
    int detector;

    if (list->type == T_HEREDOC)
    {
        detector = 1;
        if (detector == 1)
        {
            if (list->next->type == T_SPACE)
                here_tag = list->next->next->value;
            else
                here_tag = list->next->value;
            detector = 0;
        }
    }
    return(here_tag);
}

/*char *ft_stock_here_doc(t_data *data, int pipe)
{
    char *temp_buff;



}*/

void ft_test(int file[2])
{
    enum{BUF = 4096};
    char buf[BUF];
    char *read_p;

    read_p = read(file[0], buf, BUF);
    printf("BUFF = %s\n", buf);
}

int ft_read_heredoc(t_data *data)
{
    t_token *list;
    int file[2];
    int detector;
    char *str;
    char *temp;
    char *here_tag;
    
    if (pipe(file) == -1)
        return (-1);
    temp = ft_strdup("");
    str = "";
    list = data->tokens_list;
    while(list)
    {
        if (list->type == T_HEREDOC)
        {
            detector = 1;
            if (detector == 1)
            {
                if (list->next->type == T_SPACE)
                   here_tag = list->next->next->value;
                else
                    here_tag = list->next->value;
                detector = 0;
            }
            while (1)
            {
                //ici joindre les strings recuperes dans un buffer
                str = readline("> ");
                if (strcmp(str, here_tag) == 0)
                {
                  /* if (list->next->next->type != T_WORD && list->next->type == T_WORD
                        || list->next->type != T_WORD)
                        ft_lexer_error("Error: no delimiter after heredoc");*/
                    break;
                }
                temp = ft_strjoin(temp, str);
            }
        }
        list = list->next;
    }
    write(file[1], temp, ft_strlen(temp)+ 1);
    ft_test(file);
    return (0);
}