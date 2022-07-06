#include "minishell.h"

void	create_exec_list_1(t_data *data)
{
	t_token *token1;
	t_token *token2;
	t_token *token3;
	t_token *token4;
	t_token *token5;
	t_token *token6;
	data->gp_tokens_list = NULL;

	token1 = ft_malloc(data, sizeof(t_token));
	token2 = ft_malloc(data, sizeof(t_token));
	token3 = ft_malloc(data, sizeof(t_token));
	token4 = ft_malloc(data, sizeof(t_token));
	token5 = ft_malloc(data, sizeof(t_token));
	token6 = ft_malloc(data, sizeof(t_token));

	data->gp_tokens_list = token1;

	token1->type = T_CMD;
	token1->value = ft_strdup("casdt");
	ft_add_to_garbage_collector(data, token1->value);
	token1->next = token2;

	token2->type = T_REDIRECT_IN;
	token2->value = ft_strdup("file1");
	ft_add_to_garbage_collector(data, token2->value);
	token2->next = token3;

	token3->type = T_PIPE;
	token3->value = ft_strdup("|");
	ft_add_to_garbage_collector(data, token3->value);
	token3->next = token4;

	token4->type = T_REDIRECT_OUT;
	//token4->value = ft_strdup("file\"$a\" - '$a'ca");
	token4->value = ft_strdup("file2");
	ft_add_to_garbage_collector(data, token4->value);
	token4->next = token5;

	token5->type = T_CMD;
	token5->value = ft_strdup("aacat");
	ft_add_to_garbage_collector(data, token5->value);
	token5->next = token6;

	token6->type = T_REDIRECT_OUT;
	token6->value = ft_strdup("file3");
	ft_add_to_garbage_collector(data, token6->value);
	token6->next = NULL;

	ft_build_exec_list(data);
}
