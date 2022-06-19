#include "minishell.h"

// create a list of tokens in data->tokens_list
void	create_token_list_1(t_data *data)
{
	t_token *token1;
	t_token *token2;
	t_token *token3;
	t_token *token4;
	t_token *token5;
	data->tokens_list = NULL;

	token1 = ft_malloc(data, sizeof(t_token));
	token2 = ft_malloc(data, sizeof(t_token));
	token3 = ft_malloc(data, sizeof(t_token));
	token4 = ft_malloc(data, sizeof(t_token));
	token5 = ft_malloc(data, sizeof(t_token));

	data->tokens_list = token1;

	token1->type = T_WORD;
	token1->value = ft_strdup("mot1 $SsHELL suite mot1");
	ft_add_to_garbage_collector(data, token1->value);
	token1->next = token2;

	token2->type = T_WORD;
	token2->value = ft_strdup("mot2");
	ft_add_to_garbage_collector(data, token2->value);
	token2->next = token3;

	token3->type = T_WORD;
	token3->value = ft_strdup("mot3");
	ft_add_to_garbage_collector(data, token3->value);
	token3->next = token4;

	token4->type = T_WORD;
	token4->value = ft_strdup("mot4");
	ft_add_to_garbage_collector(data, token4->value);
	token4->next = token5;

	token5->type = T_WORD;
	token5->value = ft_strdup("mot5");
	ft_add_to_garbage_collector(data, token5->value);
	token5->next = NULL;
}
