#include "minishell.h"

int	ft_pwd_error(t_data *data)
{
	(void)data;
	perror(NULL);
	return (1);
}
