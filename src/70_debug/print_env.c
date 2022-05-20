#include "minishell.h"

void    print_env(char **env)
{
    while (*env)
    {
        ft_printf("%s\n", *env);
        env++;
    }
}