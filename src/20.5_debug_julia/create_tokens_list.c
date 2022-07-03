#include "minishell.h"

int ft_main(int argc, char **argv, char **envp)
{
	ft_printf(" ################## DEBUT PROGRAM  ##########################\n");
    t_data data;
	ft_initialisation(&data);

    ft_create_tokens_list(data);
}