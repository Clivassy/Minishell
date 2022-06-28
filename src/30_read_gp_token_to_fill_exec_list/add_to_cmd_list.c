#include "minishell.h"

static int	ft_cmd_len(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		i++;
	}
	return (i);
}

//static char	*increase_cmd_cmd_size()

void	ft_add_to_command_list(t_data *data, char ***cmd_lst, char *to_add)
{
	int	i;
	char **new_command;

	new_command = ft_malloc(data, sizeof(*char) * (ft_cmd_len(*cmd_lst) + 1));
	i = 0;
	while ((*cmd_list)[i])
	{
		new_command[i] = (*cmd_lst)[i];
		i++;
	}
	
}
