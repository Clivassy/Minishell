#include "minishell.h"

int ft_is_quoted(char *heretag)
{
    if (!ft_strchr(heretag, '\'') && !ft_strchr(heretag, '\"'))
        return(1);
    return(0);
}

int ft_is_expand_required(char *heretag)
{
    if (ft_strchr(heretag, '$'))
    {
       // printf("expand needed\n");
        return (1);
    }
    //printf("NO expand needed\n");
    return (0);
}
/*
void ft_test(int file[2])
{
    char buf[4096];
    char *read_p;

    read_p = read(file[0], buf, 4096);
    printf("BUFFER = %s\n", buf);
}*/