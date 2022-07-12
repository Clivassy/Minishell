#include "minishell.h"

void    ft_exit(t_data *data)
{
	//ft_print_color(COLOR_RED);
    //ft_printf("#############################################\n");
    //ft_printf("###        ft_exit function called        ###\n");
    //ft_printf("###    free garbage collector and exit    ###\n");
    //ft_printf("#############################################\n");
	//ft_print_color(COLOR_NORMAL);
	ft_free_garbage_collector(data);
    exit(0);

    // TBD
}

// renomer ft_exit et changer partout
void    ft_exit2(t_data *data, int error_status)
{
	//(COLOR_RED);
    //ft_printf("#############################################\n");
    //ft_printf("###        ft_exit function called        ###\n");
    //ft_printf("###    free garbage collector and exit    ###\n");
    //ft_printf("#############################################\n");
	//ft_print_color(COLOR_NORMAL);
	ft_free_garbage_collector(data);
    exit(error_status);

    // TBD : ajout free des fd
}
