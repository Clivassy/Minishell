#include "minishell.h"

int	ft_is_builtin(t_data *data, char **cmd)
{
	(void)data;
	if (!cmd | !(cmd)[0])
		return (0);
	if (ft_strcmp(cmd[0], "echo") == 0
		|| ft_strcmp(cmd[0], "cd") == 0
		|| ft_strcmp(cmd[0], "pwd") == 0
		|| ft_strcmp(cmd[0], "export") == 0
		|| ft_strcmp(cmd[0], "unset") == 0
		|| ft_strcmp(cmd[0], "env") == 0
		|| ft_strcmp(cmd[0], "exit") == 0)
	{
		return (1);
	}
	return (0);
}
