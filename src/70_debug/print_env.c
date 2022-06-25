#include "minishell.h"

void    ft_print_env(char **env)
{
    while (*env)
    {
        ft_printf("%s\n", *env);
        env++;
    }
}
