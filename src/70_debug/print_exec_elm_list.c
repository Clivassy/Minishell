#include "minishell.h"

void    ft_exec_elm_lst_print(t_exec_elm *elm)
{
	int i;
	int	j;

	if (!elm)
	{
		ft_printf("liste vide\n");
		return;
	}
	i= 0;
	while (elm)
	{
		ft_printf("----------------------------\n");
		ft_printf("| element %d : %p\n", i, elm);
		ft_printf("| cmd = ");
		j = 0;
		if (elm->cmd)
		{
			while ((elm->cmd)[j])
			{
				ft_printf(" '%s'", elm->cmd[j]);
				j++;
			}
			ft_printf(" '%s'", elm->cmd[j]);
		}
		else
			ft_printf("char** = NULL");
		ft_printf("\n| fd_in = %d\n", elm->fd_in);
		ft_printf("| fd_out = %d\n", elm->fd_out);
		ft_printf("| index = %d\n", elm->index);

		ft_printf("| pid = %d\n", elm->pid);

		ft_printf("| next element = %p\n", elm->next);
		ft_printf("----------------------------\n");
		ft_printf("              |             \n");
		ft_printf("              v             \n");
		elm = elm->next;
		i++;
	}
}
