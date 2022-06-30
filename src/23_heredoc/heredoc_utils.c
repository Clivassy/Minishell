#include "minishell.h"

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

