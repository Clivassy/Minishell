#include "minishell.h"

void	ft_test_rm_quotes_in_str(t_data *data)

{
	char *str = ft_strdup("\"in double 'in double'\"'in simple\"in\"'outside");
	// pour test dans bash : echo "in double 'in double'"'in simple"in"'outside
	ft_add_to_garbage_collector(data, str);

	ft_printf("str avant expand : %s\n",str);
	ft_rm_quotes_in_str(data, &str);
	ft_printf("str apres expand : %s\n", str);
}

void	ft_test_rm_quotes_in_token(t_data *data)
{
	ft_printf("token avant expand : %s\n", data->tokens_list->value);
	ft_rm_quotes_in_token(data, data->tokens_list);
	ft_printf("token apres expand : %s\n", data->tokens_list->value);
}

void	ft_test_rm_quotes_in_token_list(t_data *data)
{
	ft_printf("###### list des token avant expand ######\n");
	ft_print_color(COLOR_CYAN);
    ft_print_token_list(data->tokens_list);
	ft_print_color(COLOR_NORMAL);

	ft_rm_quotes_in_tokens_list(data);

	ft_printf("###### list des token apres expand ######\n");
	ft_print_color(COLOR_CYAN);
    ft_print_token_list(data->tokens_list);
	ft_print_color(COLOR_NORMAL);

}
