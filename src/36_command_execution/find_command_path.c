#include "minishell.h"

static char	*ft_strjoin3(t_data *data, char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*final_str;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		ft_exit(data);
	ft_add_to_garbage_collector(data, tmp);
	final_str = ft_strjoin(tmp, s3);
	if (!final_str)
		ft_exit(data);
	ft_add_to_garbage_collector(data, final_str);
	ft_free(data, tmp);
	printf ("tmp and finaltr %p %p\n", tmp, final_str);
	return (final_str);
}


static void	ft_free_pointer_array(t_data *data, char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

// check if 1 path is valid in the paths list and return the 1st valid
char	*ft_check_path_command(t_data *data, char **paths, char *cmd)
{
	int		j;
	char	*full_path;

	j = 0;
	while (paths[j])
	{
		full_path = ft_strjoin3(data, paths[j], "/", cmd);
		if (!full_path)
			ft_exit(data);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		else
			ft_free(data, full_path);
		j++;
	}
	return (NULL);
}

char	*ft_find_command(t_data *data, char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
			{
				ft_exit(data);
			}
			full_path = ft_check_path_command(data, paths, cmd);
			if (full_path)
			{
				ft_free_pointer_array(data, paths);
				return (full_path);
			}
			// check que path soit bien free a tous les coups ?
		}
		i++;
	}
	ft_free_pointer_array(data, paths);
	return (NULL);
}

void	ft_launch_command(t_data *data, char **cmd, char **envp)
{
	char	**cmd_split;
	char	*command_with_path;

	//cmd_split = ft_split(cmd, ' ');
	//if (!cmd_split)
	//	ft_error("malloc error"); // revoir les erreurs
	command_with_path = ft_find_command(data, cmd[0], envp);
	execve(command_with_path, cmd, envp); // revoir retour erreur (ligne dessous)

	//if (execve(command_with_path, cmd_split, envp) == -1)
	//	ft_error("error in command execution");
	//ft_error("error on function launch_command");
}
