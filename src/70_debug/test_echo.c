#include "minishell.h"

void    ft_test_echo()
{
    char *arg1[5] = {"1ola", "como", "estas", "!",NULL};
    ft_echo(arg1);
    ft_printf("--- \n");

    char *arg2[6] = {"2ola", "-n", "como", "estas", "!",NULL};
    ft_echo(arg2);
    ft_printf("--- \n");

    char *arg3[7] = {"3ola", "como", "-n", "estas", "-n", "!",NULL};
    ft_echo(arg3);
    ft_printf("--- \n");

    char *arg4[7] = {"4ola", "como", "-n", "estas", "!", "-n",NULL};
    ft_echo(arg4);
    ft_printf("--- \n");

    char *arg5[8] = {"-n", "5ola", "como", "-n", "estas", "!", "-n",NULL};
    ft_echo(arg5);
    ft_printf("-- \n");

    char *arg6[8] = {"-n", "-n", "6ola", "como", "-n", "estas", "!", NULL};
    ft_echo(arg6);
    ft_printf("-- \n");

    char *arg7[2] = {"-n", NULL};
    ft_echo(arg7);
    ft_printf("-- \n");

    char *arg8[1] = {NULL};
    ft_echo(arg8);
    ft_printf("-- \n");

    char *arg9[2] = {"-na", NULL};
    ft_echo(arg9);
    ft_printf("-- \n");
}