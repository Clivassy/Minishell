#include "minishell.h"

void	ft_test_command_execution(t_data *data)
{
	create_exec_list_1(data);

	ft_print_color(COLOR_GREEN);
	ft_printf("###### token list ######\n");
	ft_print_token_list(data->gp_tokens_list);
	ft_print_color(COLOR_NORMAL);

	ft_exec_all_cmds(data);

	ft_print_color(COLOR_CYAN);
	ft_printf("###### exec list testee ######\n");
    ft_exec_elm_lst_print(data->exec_list);
	ft_print_color(COLOR_NORMAL);


}
