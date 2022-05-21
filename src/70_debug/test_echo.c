#include "minishell.h"


// comportement attendu
// 1er paramettre peut c
void    ft_test_echo()
{
	ft_printf("test 1 : --->");
    char *arg1[5] = {"ola", "como", "estas", "!",NULL};
    ft_echo(arg1);
    ft_printf("<--- \n");

	ft_printf("test 2 : --->");

    char *arg2[6] = {"ola", "-n", "como", "estas", "!",NULL};
    ft_echo(arg2);
    ft_printf("<--- \n");

	ft_printf("test 3 : --->");
    char *arg3[7] = {"ola", "como", "-n", "estas", "-n", "!",NULL};
    ft_echo(arg3);
    ft_printf("<--- \n");

	ft_printf("test 4 : --->");
    char *arg4[7] = {"ola", "como", "-n", "estas", "!", "-n",NULL};
    ft_echo(arg4);
    ft_printf("<--- \n");

	ft_printf("test 5 : --->");
    char *arg5[8] = {"-n", "ola", "como", "-n", "estas", "!", "-n",NULL};
    ft_echo(arg5);
    ft_printf("<-- \n");

	ft_printf("test 6 : --->");
    char *arg6[8] = {"-n", "-n", "ola", "como", "-n", "estas", "!", NULL};
    ft_echo(arg6);
    ft_printf("<-- \n");

	ft_printf("test 7 : --->");
    char *arg7[2] = {"-n", NULL};
    ft_echo(arg7);
    ft_printf("<-- \n");

	ft_printf("test 8 : --->");
    char *arg8[1] = {NULL};
    ft_echo(arg8);
    ft_printf("<-- \n");

	ft_printf("test 9 : --->");
    char *arg9[2] = {"-", NULL};
    ft_echo(arg9);
    ft_printf("<-- \n");

	ft_printf("test 10 : --->");
	char *arg10[2] = {"-na", NULL};
    ft_echo(arg10);
    ft_printf("<-- \n");

	ft_printf("test 11 : --->");
	char *arg11[2] = {"-nnnnnn", NULL};
    ft_echo(arg11);
    ft_printf("<-- \n");

	ft_printf("test 12 : --->");
	char *arg12[3] = {"-n", "-nnn", NULL};
    ft_echo(arg12);
    ft_printf("<-- \n");

	ft_printf("test 13 : --->");
	char *arg13[3] = {"-n", "-nnns", NULL};
    ft_echo(arg13);
    ft_printf("<-- \n");
}
