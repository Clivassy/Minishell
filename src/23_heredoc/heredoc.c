
/*----------------------------- PARSER ------------------------------
Gestion des heredocs + erreurs de syntaxe de heredocs 
// realine pour recuperer tout ce qui vient jusqu'au EOF  
- stocké dans un pipe.
- j'expand ce qui est a l'intérieur si jamais il y a des variables d'emvironnement
- ?? 
----------------------------------------------------------------------*/
/*
t_token    *ft_simulation_token(t_token *heretag)
{
    heretag = malloc(sizeof(t_token));
    heretag->type = T_WORD;
    heretag->value = "end";

    printf("TOKEN VALUE : %s\n", heretag->value);
    printf("TOKEN TYPE : %d\n", heretag->type);
}

void ft_test(int file[2])
{
    enum{BUF = 4096};
    char buf[BUF];
    char *read_p;

    read_p = read(file[0], buf, BUF);
    printf("BUFF = %s\n", buf);
}

// ++ft_strcmp
*//*
int ft_heredoc(t_data *data, t_token *heredoc_tkn)
{
    t_token *heretag;
    heretage = ft_simulation_token(heretag);
    char *str;
    int fd[2];

    pipe(fd);
    str = ft_read_heredoc(heretag, str);
    write(fd[1], str, ft_strlen(str)+ 1);
    ft_test(fd);
    return (fd[0]);
}*/
/*
char   *ft_found_heretag(t_token *list, int detector, char *here_tag)
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
    return(here_tag);
}

char *ft_stock_here_doc(char *str, char *temp, char *here_tag)
{
    while (1)
    {
        str = readline("> ");
        temp = ft_strjoin(temp, "\n");
        if (strcmp(str, here_tag) == 0)
            break;
        else
            temp = ft_strjoin(temp, str);
    }
    return(temp);
}*/

/*char *ft_read_heredoc(t_token *elem, char *str)
{
    t_token *list;
    int detector;
    char *temp;
    char *here_tag;

    temp = ft_strdup("");
    list = data->tokens_list;
    while(list)
    {
        if (list->type == T_HEREDOC)
        {
            here_tag = ft_found_heretag(list, detector, here_tag);
            temp = ft_stock_here_doc(list, str, temp, here_tag);
        }
        list = list->next;
    }
    return (temp);
}*/
/*
char *ft_read_heredoc(t_token *elem, char *str)
{
    char *temp;
    char *here_tag;
    
    here_tag = elem->value;
    printf("ELEM : %s\n", here_tag);
    temp = ft_strdup("");
    temp = ft_stock_here_doc(str, temp, here_tag);

    return (temp);
} */

