#include "minishell.h"

void    ft_exit(t_data *data)
{
	ft_print_color(COLOR_RED);
    ft_printf("#############################################\n");
    ft_printf("###        ft_exit function called        ###\n");
    ft_printf("###    free garbage collector and exit    ###\n");
    ft_printf("#############################################\n");
	ft_print_color(COLOR_NORMAL);
	ft_free_garbage_collector(data);
    exit(0);

    // TBD
}
