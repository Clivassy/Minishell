#include "minishell.h"

void    ft_test_cd(t_data *data)
{
	ft_print_color(COLOR_CYAN);

	char *buff = NULL;

	ft_printf("repertoire courant = %s\n", getcwd(buff, 0));

	ft_print_color(COLOR_GREEN);
	char *cmd1[5] = {"cd", "/mnt/nfs/homes/ybellot/Documents/minishell",NULL};
	ft_builtin_cd(data, cmd1);
	ft_printf("repertoire courant1 = %s\n\n", getcwd(buff, 0));

	char *cmd2[5] = {"cd", ".",NULL};
	ft_builtin_cd(data, cmd2);
	ft_printf("repertoire courant2 = %s\n\n", getcwd(buff, 0));

	char *cmd3[5] = {"cd", "..",NULL};
	ft_builtin_cd(data, cmd3);
	ft_printf("repertoire courant3 = %s\n\n", getcwd(buff, 0));

	char *cmd4[5] = {"cd", "../Documents/./minishell",NULL};
	ft_builtin_cd(data, cmd4);
	ft_printf("repertoire courant4 = %s\n\n", getcwd(buff, 0));

	char *cmd5[5] = {"cd", ".././../mauvais rep",NULL};
	ft_builtin_cd(data, cmd5);
	ft_printf("repertoire courant5 = %s\n\n", getcwd(buff, 0));

	ft_printf("Trop d'arguments\n");
	char *cmd6[5] = {"cd", ".././../mauvais rep", "trop",NULL};
	ft_builtin_cd(data, cmd6);
	ft_printf("repertoire courant6 = %s\n\n", getcwd(buff, 0));

	ft_printf("Pas d'arguments\n");
	char *cmd7[5] = {"cd",NULL};
	ft_builtin_cd(data, cmd7);
	ft_printf("repertoire courant7 = %s\n\n", getcwd(buff, 0));

	//ft_printf("nombre de ligne env : %d\n", ft_env_nb_of_lines(data->env));

	//ft_printf("value associe a la cle PWD: %s\n", ft_env_get_value(data, "PWD"));
	//ft_printf("value associe a la cle XMODIFIERS: %s\n", ft_env_get_value(data, "XMODIFIERS"));

	ft_print_color(COLOR_NORMAL);

}

void    ft_test_pwd(t_data *data)
{
	ft_print_color(COLOR_CYAN);

	char *buff = NULL;

	ft_printf("repertoire courant = %s\n", getcwd(buff, 0));

	ft_print_color(COLOR_GREEN);

	ft_printf("1 -test normal PWD = %s\n", getcwd(buff, 0));
	char *cmd1[5] = {"pwd",NULL};
	ft_builtin_pwd(data, cmd1);

	ft_printf("2- test trop d'argument (pas d'erreur attendue) PWD = %s\n", getcwd(buff, 0));
	char *cmd2[5] = {"pwd", "arg1",NULL};
	ft_builtin_pwd(data, cmd2);

}

