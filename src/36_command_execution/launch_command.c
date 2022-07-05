#include "minishell.h"

void	ft_launch_command(t_data *data, char **cmd, char **envp)
{
	char	**cmd_split;
	char	*command_with_path;

	// TBD AJOUT recherche de built in

	//cmd_split = ft_split(cmd, ' ');
	//if (!cmd_split)
	//	ft_error("malloc error"); // revoir les erreurs
	command_with_path = ft_find_command(data, cmd[0], envp);
	execve(command_with_path, cmd, envp); // revoir retour erreur (ligne dessous)

	//if (execve(command_with_path, cmd_split, envp) == -1)
	//	ft_error("error in command execution");
	//ft_error("error on function launch_command");
}
