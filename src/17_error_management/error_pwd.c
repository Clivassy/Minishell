#include "minishell.h"

int	ft_pwd_error(t_data *data)
{
	perror(NULL);
	return (1);
}
