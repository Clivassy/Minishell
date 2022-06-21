#include "minishell.h"

void	ft_test_rm_quotes_in_token(t_data *data)
{
	ft_printf("token avant expand : %s\n", data->tokens_list->value);
	ft_rm_quotes_in_token(data, data->tokens_list);
	ft_printf("token apres expand : %s\n", data->tokens_list->value);
}


//void	ft_test_expand_token(t_data *data)
//{
//	ft_printf("token avant expand : %s\n", data->tokens_list->value);
//	ft_expand_token(data, data->tokens_list);
//	ft_printf("token apres expand : %s\n", data->tokens_list->value);
//}

//void	ft_test_expand(t_data *data)
//{
//	ft_printf("###### list des token avant expand ######\n");
//	ft_print_color(COLOR_CYAN);
//    ft_print_token_list(data->tokens_list);
//	ft_print_color(COLOR_NORMAL);

//	ft_expand(data);

//	ft_printf("###### list des token apres expand ######\n");
//	ft_print_color(COLOR_CYAN);
//    ft_print_token_list(data->tokens_list);
//	ft_print_color(COLOR_NORMAL);

//}
