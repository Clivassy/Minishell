#include "minishell.h"

void	ft_test_ft_set_exec_t_redirect_in(t_data *data)
{
	create_gp_token_list_1(data);


	ft_printf("###### list des token_gp ######\n");
	ft_print_color(COLOR_CYAN);
    ft_print_token_list(data->gp_tokens_list);
	ft_print_color(COLOR_NORMAL);

	//ft_create_exec_elm_list(data);
	ft_exec_elm_lst_print(data->exec_list);

	ft_build_exec_list(data);

	ft_printf("###### list des token apres expand ######\n");
	ft_print_color(COLOR_GREEN);
	ft_exec_elm_lst_print(data->exec_list);
	ft_print_color(COLOR_NORMAL);
}
