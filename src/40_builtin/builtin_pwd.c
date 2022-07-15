#include "minishell.h"

int	ft_builtin_pwd(t_data *data, char **cmd)
{
	(void)cmd;
	char	*path;

	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		return (ft_pwd_error(data));
	ft_add_to_garbage_collector(data, path);
	ft_printf("%s\n", path);
	ft_free(data, path);
	return (0);
}
