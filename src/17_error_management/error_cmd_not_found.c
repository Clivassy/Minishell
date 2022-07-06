#include "minishell.h"

void	ft_exit_cmd_not_found_error(t_data *data, char **cmd)
{
	write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0])); // voir si on redirge bien std err
	write(STDERR_FILENO, ": Command Not Found\n", 20); // voir si on redirge bien std err
	ft_exit2(data, EXIT_CODE_COMMAND_NOT_FOUND);
}
