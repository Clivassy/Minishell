#include "minishell.h"

int	ft_cd_error_too_many_arg(t_data *data)
{
	(void)data;
	write(STDERR_FILENO, "bash: cd: too many arguments\n", 29);
	return (1);
}

int	ft_cd_error_no_arg(t_data *data)
{
	(void)data;
	write(STDERR_FILENO, "bash: cd: no argument\n", 22);
	return (1);
}

int	ft_cd_error_no_dir(t_data *data, char *cmd)
{
	(void)data;
	write(STDERR_FILENO, "bash: cd: ", ft_strlen("bash: cd: "));
	write(STDERR_FILENO, "%s", ft_strlen(cmd));
	write(STDERR_FILENO, ": No such file or directory\n",
		ft_strlen(": No such file or directory\n"));
	return (1);
}
