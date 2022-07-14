#include "minishell.h"

// lance le builtin qui doit stocker le statut de retour dans data
void	ft_exec_builtin(t_data *data, char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		data->last_pipeline_exit_status = ft_builtin_echo(data, cmd);
	if (ft_strcmp(cmd[0], "cd") == 0)
		data->last_pipeline_exit_status = ft_builtin_cd(data, cmd);
	if (ft_strcmp(cmd[0], "pwd") == 0)
		data->last_pipeline_exit_status = ft_builtin_pwd(data, cmd);
	if (ft_strcmp(cmd[0], "export") == 0)
		data->last_pipeline_exit_status = ft_builtin_export(data, cmd);
	if (ft_strcmp(cmd[0], "unset") == 0)
		data->last_pipeline_exit_status = ft_builtin_unset(data, cmd);
	if (ft_strcmp(cmd[0], "env") == 0)
		data->last_pipeline_exit_status = ft_builtin_env(data, cmd);
	if (ft_strcmp(cmd[0], "exit") == 0)
		data->last_pipeline_exit_status = ft_builtin_exit(data, cmd);
}

void	ft_exec_one_command(t_data *data, t_exec_elm *exec_elm)
{
	char	*command_with_path;

	if (exec_elm->has_redirect_pb == 1)
		ft_exit2(data, 1);
	if (!exec_elm->cmd)
		ft_exit2(data, 0);
	ft_make_fd_redirection(data, exec_elm);
	if (ft_is_builtin(data, exec_elm->cmd))
	{
		ft_exec_builtin(data, exec_elm->cmd);
		ft_exit2(data, data->last_pipeline_exit_status);
	}
	command_with_path = ft_find_command(data, (exec_elm->cmd)[0], data->env);
	if (!command_with_path)
	{
		ft_exit_cmd_not_found_error(data, exec_elm->cmd);
	}
	execve(command_with_path, exec_elm->cmd, data->env);
	ft_exit_execve_error(data);
}
