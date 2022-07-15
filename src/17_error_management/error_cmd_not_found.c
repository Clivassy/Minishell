#include "minishell.h"

/*voir si on redirge bien std err*/
void	ft_exit_cmd_not_found_error(t_data *data, char **cmd)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0]));
	write(STDERR_FILENO, ": Command Not Found\n", 20);
	ft_exit2(data, EXIT_CODE_COMMAND_NOT_FOUND);
}
