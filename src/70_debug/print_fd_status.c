#include "minishell.h"
#include <fcntl.h>


int	ft_print_fd_status(char *message)
{
	int i = 0;
	int statut;
	ft_print_color(COLOR_MAGENTA);

	if (mes)

	while (i <10)
	{
		statut = fcntl(i, F_GETFL);
		printf("fd: %d - statut: %d\n", i, statut);
		i++;
	}
	ft_print_color(COLOR_NORMAL);

}
