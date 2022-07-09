#include "minishell.h"

void	ft_cd(char **arguments)
{
	// var d'env PWD pour repertoire courrant
	// cd sans arguments ouvre repertoire de la variable d'env HOME
	// The return status is zero if the directory is successfully changed, non-zero otherwise.

	// use getcwd() chdir()
	chdir("/mnt/nfs/homes/ybellot/Documents/");
	char *buf = malloc(sizeof(char) * 500);
	getcwd(buf, 500);
	ft_printf("buf : %s\n", buf);

}
