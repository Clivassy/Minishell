#include "minishell.h"

// a faire
int	ft_builtin_cd(t_data *data, char **cmd)
{
	// var d'env PWD pour repertoire courrant
	// cd sans arguments ouvre repertoire de la variable d'env HOME
	// The return status is zero if the directory is successfully changed, non-zero otherwise.

	// commandes utiles ? --> getcwd() chdir()

	//chdir("/mnt/nfs/homes/ybellot/Documents/");
	//char *buf = malloc(sizeof(char) * 500);
	//getcwd(buf, 500);
	//ft_printf("buf : %s\n", buf);

	int error_status;

	if (ft_null_terminated_tab_len(cmd) < 2)
		return (ft_cd_error_no_arg(data));
	if (ft_null_terminated_tab_len(cmd) > 2)
		return (ft_cd_error_too_many_arg(data));
	error_status = chdir(cmd[1]);
	if (error_status != 0)
	{
		return (ft_cd_error_no_dir(data, cmd[1]));
	}
	else
	{
		return (0);
	}

}
