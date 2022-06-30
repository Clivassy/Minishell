#include "minishell.h"

void    ft_print_token_list(t_token *token_list)
{
	if (!token_list)
	{
		ft_printf("liste vide\n");
		exit(EXIT_FAILURE);
	}
	while (token_list != NULL)
	{
		ft_printf("----------------------------\n");
		ft_printf("| value = [%s]", token_list->value);
		ft_printf("\n| type = %d\n", token_list->type);
		ft_printf("| next element = %p\n", token_list->next);
		ft_printf("----------------------------\n");
		ft_printf("              |             \n");
		ft_printf("              v             \n");
		token_list = token_list->next;
	}
}
