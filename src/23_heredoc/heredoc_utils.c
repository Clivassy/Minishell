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
        printf("expand needed\n");
        return (1);
    }
    printf("NO expand needed\n");
    return (0);
}

void ft_test(int file[2])
{
    enum{BUF = 4096};
    char buf[BUF];
    char *read_p;

    read_p = read(file[0], buf, BUF);
    printf("BUFF = %s\n", buf);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

