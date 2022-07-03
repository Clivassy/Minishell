
#include "minishell.h"


void	ft_test_expand_str(t_data *data)
{
	char *str = ft_strdup("mot1 $PWD suite mot1");
	ft_add_to_garbage_collector(data, str);

	ft_printf("token avant expand : %s\n",str);
	ft_expand_str(data, &str);
	ft_printf("token apres expand : %s\n", str);
}

void	ft_test_expand_token(t_data *data)
{
	create_token_list_1(data);

	ft_printf("token avant expand : %s\n", data->tokens_list->value);
	ft_expand_token(data, data->tokens_list);
	ft_printf("token apres expand : %s\n", data->tokens_list->value);
}

void	ft_test_expand(t_data *data)
{
	create_token_list_1(data);

	ft_printf("###### list des token avant expand ######\n");
	ft_print_color(COLOR_CYAN);
    ft_print_token_list(data->tokens_list);
	ft_print_color(COLOR_NORMAL);

	ft_expand(data);

	ft_printf("###### list des token apres expand ######\n");
	ft_print_color(COLOR_CYAN);
    ft_print_token_list(data->tokens_list);
	ft_print_color(COLOR_NORMAL);

}
