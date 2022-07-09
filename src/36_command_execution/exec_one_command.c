#include "minishell.h"


// lance le builtin qui doit stocker le statut de retour dans data
void	ft_exec_builtin(t_data *data, char **cmd)
{
	//// a completer avec les builtins (faire exit(STATUS_EXIT) dans chaque builtin)
	if (ft_strcmp(cmd[0], "echo") == 0)
	{
		ft_echo(cmd);
	}
	if (ft_strcmp(cmd[0], "cd") == 0)
	{
		// lancer builtin cd
	}
	if (ft_strcmp(cmd[0], "pwd") == 0)
	{
		// lancer builtin pwd
	}
	if (ft_strcmp(cmd[0], "export") == 0)
	{
		// lancer builtin export
	}
	if (ft_strcmp(cmd[0], "unset") == 0)
	{
		// lancer builtin unset
	}
	if (ft_strcmp(cmd[0], "env") == 0)
	{
		// lancer builtin env
	}
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		ft_builtin_exit(data);
	}
	//else
	//	return ;
}




void	ft_exec_one_command(t_data *data, t_exec_elm *exec_elm)
{
	char	*command_with_path;

	if (exec_elm->has_redirect_pb == 1)
	{
		ft_close_fd_exept_current(data, -1);
		ft_exit2(data, 1);
	}
	if (!exec_elm->cmd)
		ft_exit2(data, 0);
	ft_make_fd_redirection(data, exec_elm);
	if (ft_is_builtin(data, exec_elm->cmd))
	{
		ft_exec_builtin(data, exec_elm->cmd);
		ft_exit2(data, data->last_pipeline_exit_status);
	}


	//cmd_split = ft_split(cmd, ' ');
	//if (!cmd_split)
	//	ft_error("malloc error"); // revoir les erreurs
	command_with_path = ft_find_command(data, (exec_elm->cmd)[0], data->env);
	if (!command_with_path)
	{
		ft_exit_cmd_not_found_error(data, exec_elm->cmd);
	}
	execve(command_with_path, exec_elm->cmd, data->env); // revoir retour erreur (ligne dessous)
	//sleep(3);
	//if (execve(command_with_path, cmd_split, envp) == -1)
	//	ft_error("error in command execution");
	//ft_error("error on function launch_command");

	exit(127); // voir comment exit le processus quand on saura pour les codes erreur
}

// old

//void	ft_launch_command(t_data *data, char **cmd, char **envp)
//{
//	char	**cmd_split;
//	char	*command_with_path;



//	ft_launch_cmd_if_is_builtin(data, cmd, envp);


//	//cmd_split = ft_split(cmd, ' ');
//	//if (!cmd_split)
//	//	ft_error("malloc error"); // revoir les erreurs
//	command_with_path = ft_find_command(data, cmd[0], envp);
//	if (!command_with_path)
//	{
//		ft_cmd_not_found_error(data, cmd);
//	}
//	execve(command_with_path, cmd, envp); // revoir retour erreur (ligne dessous)

//	//if (execve(command_with_path, cmd_split, envp) == -1)
//	//	ft_error("error in command execution");
//	//ft_error("error on function launch_command");
//}
