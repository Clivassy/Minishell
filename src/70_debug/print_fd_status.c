#include "minishell.h"
#include <fcntl.h>

// ecriture dans fd 2 (stderr)
void	ft_print_fd_status(char *message)
{
	int i = 0;
	int statut;
	fprintf(stderr, COLOR_MAGENTA);

	if (message)
		fprintf(stderr,"#### %s ####\n", message);

	while (i <10)
	{
		statut = fcntl(i, F_GETFL);
		fprintf(stderr,"fd: %d - statut: %d\n", i, statut);
		i++;
	}

	fprintf(stderr, COLOR_NORMAL);
}
