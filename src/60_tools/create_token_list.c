#include "minishell.h"

// create a list of tokens in data->tokens_list
void	create_token_list_1(t_data *data)
{
	t_token *token1;
	t_token *token2;
	t_token *token3;
	t_token *token4;
	t_token *token5;
	t_token *token6;
	data->tokens_list = NULL;

	token1 = ft_malloc(data, sizeof(t_token));
	token2 = ft_malloc(data, sizeof(t_token));
	token3 = ft_malloc(data, sizeof(t_token));
	token4 = ft_malloc(data, sizeof(t_token));
	token5 = ft_malloc(data, sizeof(t_token));
	token6 = ft_malloc(data, sizeof(t_token));

	data->tokens_list = token1;

	token1->type = T_WORD;
	token1->value = ft_strdup("mot1 $SsHELL suite mot1");
	ft_add_to_garbage_collector(data, token1->value);
	token1->next = token2;

	token2->type = T_WORD;
	token2->value = ft_strdup("mot1 $SHELL$SHELL suite $SHELL");
	ft_add_to_garbage_collector(data, token2->value);
	token2->next = token3;

	token3->type = T_WORD;
	token3->value = ft_strdup("\"mot1 $SHELL suite mot1\"");
	ft_add_to_garbage_collector(data, token3->value);
	token3->next = token4;

	token4->type = T_WORD;
	token4->value = ft_strdup("\'mot1 $SHELL suite mot1\'");
	ft_add_to_garbage_collector(data, token4->value);
	token4->next = token5;

	token5->type = T_WORD;
	token5->value = ft_strdup("lastpipelinestatus $?motcolle $SHELL quote \' $? $SHELL\'");
	ft_add_to_garbage_collector(data, token5->value);
	token5->next = token6;

	token6->type = T_WORD;
	token6->value = ft_strdup("\"mot1\"\n'mot2 $SHELL ' \nmot 3 $SHELL \n\"mot 4 $SHELL \"\nmot 5");
	ft_add_to_garbage_collector(data, token6->value);
	token6->next = NULL;
}

void	create_token_list_2(t_data *data)
{
	t_token *token1;
	t_token *token2;
	t_token *token3;
	t_token *token4;
	t_token *token5;
	t_token *token6;
	data->tokens_list = NULL;

	token1 = ft_malloc(data, sizeof(t_token));
	token2 = ft_malloc(data, sizeof(t_token));
	token3 = ft_malloc(data, sizeof(t_token));
	token4 = ft_malloc(data, sizeof(t_token));
	//token5 = ft_malloc(data, sizeof(t_token));
	//token6 = ft_malloc(data, sizeof(t_token));

	data->tokens_list = token1;

	token1->type = T_WORD;
	token1->value = ft_strdup("\"in double 'in double'\"'in simple\"in\"'outside");
	// pour test dans bash : echo "in double 'in double'"'in simple"in"'outside
	ft_add_to_garbage_collector(data, token1->value);
	token1->next = token2;

	token2->type = T_WORD;
	token2->value = ft_strdup("");
	ft_add_to_garbage_collector(data, token2->value);
	token2->next = token3;

	token3->type = T_WORD;
	token3->value = ft_strdup("''");
	ft_add_to_garbage_collector(data, token3->value);
	token3->next = token4;

	token4->type = T_WORD;
	token4->value = ft_strdup("\"\"");
	ft_add_to_garbage_collector(data, token4->value);
	//token4->next = token5;
	token4->next = NULL;
}

void	create_token_list_3(t_data *data)
{
	t_token *token1;
	t_token *token2;
	t_token *token3;
	t_token *token4;
	t_token *token5;
	t_token *token6;
	data->tokens_list = NULL;

	token1 = ft_malloc(data, sizeof(t_token));
	token2 = ft_malloc(data, sizeof(t_token));
	token3 = ft_malloc(data, sizeof(t_token));
	token4 = ft_malloc(data, sizeof(t_token));
	token5 = ft_malloc(data, sizeof(t_token));
	token6 = ft_malloc(data, sizeof(t_token));

	data->tokens_list = token1;

	token1->type = T_WORD;
	token1->value = ft_strdup("mot1");
	ft_add_to_garbage_collector(data, token1->value);
	token1->next = token2;

	token2->type = T_REDIRECT_IN;
	token2->value = ft_strdup("<");
	ft_add_to_garbage_collector(data, token2->value);
	token2->next = token3;

	token3->type = T_PIPE;
	token3->value = ft_strdup("|");
	ft_add_to_garbage_collector(data, token3->value);
	token3->next = token4;

	token4->type = T_WORD;
	token4->value = ft_strdup("\'mot1 $SHELL suite mot1\'");
	ft_add_to_garbage_collector(data, token4->value);
	token4->next = token5;

	token5->type = T_PIPE;
	token5->value = ft_strdup("|");
	ft_add_to_garbage_collector(data, token5->value);
	token5->next = token6;

	token6->type = D_REDIRECT_OUT;
	token6->value = ft_strdup(">");
	ft_add_to_garbage_collector(data, token6->value);
	token6->next = NULL;
}

void	create_token_list_empty(t_data *data)
{
	data->tokens_list = NULL;
}

void	create_token_list_1_elm(t_data *data)
{
	t_token *token1;

	data->tokens_list = NULL;
	token1 = ft_malloc(data, sizeof(t_token));
	data->tokens_list = token1;

	token1->type = T_WORD;
	token1->value = ft_strdup("mot1");
	ft_add_to_garbage_collector(data, token1->value);
	token1->next = NULL;
}

void	create_token_list_3elm_avec_pipe(t_data *data)
{
	t_token *token1;
	t_token *token2;
	t_token *token3;
	data->tokens_list = NULL;

	token1 = ft_malloc(data, sizeof(t_token));
	token2 = ft_malloc(data, sizeof(t_token));
	token3 = ft_malloc(data, sizeof(t_token));

	data->tokens_list = token1;

	token1->type = T_WORD;
	token1->value = ft_strdup("mot1");
	ft_add_to_garbage_collector(data, token1->value);
	token1->next = token2;

	token2->type = T_PIPE;
	token2->value = ft_strdup("|");
	ft_add_to_garbage_collector(data, token2->value);
	token2->next = token3;

	token3->type = T_WORD;
	token3->value = ft_strdup("mot2");
	ft_add_to_garbage_collector(data, token3->value);
	token3->next = NULL;
}

void	create_gp_token_list_1(t_data *data)
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
	token1->value = ft_strdup("ls");
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
	token4->value = ft_strdup("file\"$a\" - '$a'ca");
	ft_add_to_garbage_collector(data, token4->value);
	token4->next = token5;

	token5->type = D_REDIRECT_OUT;
	token5->value = ft_strdup("file\"$a\" - '$a'ca");
	ft_add_to_garbage_collector(data, token5->value);
	token5->next = token6;

	token6->type = T_CMD;
	token6->value = ft_strdup("checkexpand-$PWD");
	ft_add_to_garbage_collector(data, token6->value);
	token6->next = NULL;
}
