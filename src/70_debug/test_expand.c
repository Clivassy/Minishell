
#include "minishell.h"

void	ft_test_expand_token(t_data *data)
{
	ft_printf("token avant expand : %s\n", data->tokens_list->value);
	ft_expand_token(data, data->tokens_list);
	ft_printf("token apres expand : %s\n", data->tokens_list->value);



}
