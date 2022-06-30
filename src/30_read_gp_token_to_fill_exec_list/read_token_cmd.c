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

void	ft_set_exec_with_t_cmd_token(t_data *data, t_token *token, int process)
{
	t_exec_elm	*current_exec_elm;
	char		**cmd_lst;
	char		**new_command;
	int			i;

	ft_expand_token(data, token);
	ft_rm_quotes_in_token(data, token);
	current_exec_elm = ft_get_exec_elm(data->exec_list, process);
	cmd_lst = ft_get_exec_elm(data->exec_list, process)->cmd;
	new_command = ft_malloc(data, sizeof(char*) * (ft_cmd_len(cmd_lst) + 2));
	i = 0;
	while ((cmd_lst)[i])
	{
		new_command[i] = cmd_lst[i];
		i++;
	}
	new_command[i] = token->value;
	new_command[i + 1] = NULL;
	ft_free(data, cmd_lst);
	ft_get_exec_elm(data->exec_list, process)->cmd = new_command;
}

// save separation en 2 fct ok
// void	ft_set_exec_with_t_cmd_token(t_data *data, t_token *token, int process)
// {
// 	t_exec_elm *current_exec_elm;
// 	char	**cmd_lst;
// 	char	*to_add;

// 	current_exec_elm = ft_get_exec_elm(data->exec_list, process);
// 	to_add = token->value;
// 	ft_add_to_command_list(data, &(current_exec_elm->cmd), to_add);
// 	// ft_get_exec_elm(data->exec_list, process)->cmd = cmd_lst;
// }

// void	ft_add_to_command_list(t_data *data, char ***cmd_lst, char *to_add)
// {
// 	int	i;
// 	char **new_command;

// 	ft_printf("to_add %s\n", to_add);
// 	new_command = ft_malloc(data, sizeof(char*) * (ft_cmd_len(*cmd_lst) + 1));
// 	i = 0;
// 	while ((*cmd_lst)[i])
// 	{
// 		printf("##### debug test #####\n");
// 		new_command[i] = (*cmd_lst)[i];
// 		i++;
// 	}
// 	new_command[i] = to_add;
// 	new_command[i + 1] = NULL;
// 	// ft_printf("cmd 0 %s\n", new_command[0]);
// 	// ft_printf("cmd 1 %s\n", new_command[1]);

// 	// ft_free_cmd_lst(data, *cmd_lst);
// 	*cmd_lst = new_command;
// }
