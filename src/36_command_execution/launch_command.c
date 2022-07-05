#include "minishell.h"

// lance commande passee en parametre si c'est un builtin (chaque command doit exit proprement)
// return sinon
void	ft_launch_cmd_if_is_builtin(t_data *data, char **cmd, char **envp)
{
	//// a completer avec les builtins (faire exit(STATUS_EXIT) dans chaque builtin)
	//if (ft_strcmp(cmd[0], "echo") == 0)
	//{
	//	// lancer builtin echo
	//}
	//if (ft_strcmp(cmd[0], "cd") == 0)
	//{
	//	// lancer builtin cd
	//}
	//if (ft_strcmp(cmd[0], "pwd") == 0)
	//{
	//	// lancer builtin pwd
	//}
	//if (ft_strcmp(cmd[0], "export") == 0)
	//{
	//	// lancer builtin export
	//}
	//if (ft_strcmp(cmd[0], "unset") == 0)
	//{
	//	// lancer builtin unset
	//}
	//if (ft_strcmp(cmd[0], "env") == 0)
	//{
	//	// lancer builtin env
	//}
	//if (ft_strcmp(cmd[0], "exit") == 0)
	//{
	//	// lancer builtin exit
	//}
	//else
	//	return ;
}

void	ft_cmd_not_found_error(t_data *data, char **cmd)
{
	write(STDERR_FILENO, cmd[0], ft_strlen(cmd[0])); // voir si on redirge bien std err
	write(STDERR_FILENO, ": Command Not Found\n", 20); // voir si on redirge bien std err
	ft_exit2(data, EXIT_CODE_COMMAND_NOT_FOUND);
}

void	ft_launch_command(t_data *data, char **cmd, char **envp)
{
	char	**cmd_split;
	char	*command_with_path;

	ft_launch_cmd_if_is_builtin(data, cmd, envp);


	//cmd_split = ft_split(cmd, ' ');
	//if (!cmd_split)
	//	ft_error("malloc error"); // revoir les erreurs
	command_with_path = ft_find_command(data, cmd[0], envp);
	if (!command_with_path)
	{
		ft_cmd_not_found_error(data, cmd);
	}
	execve(command_with_path, cmd, envp); // revoir retour erreur (ligne dessous)

	//if (execve(command_with_path, cmd_split, envp) == -1)
	//	ft_error("error in command execution");
	//ft_error("error on function launch_command");
}
