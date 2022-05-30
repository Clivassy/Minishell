#include "minishell.h"
/*--------------------------------------------------------------------
Fonctions qui vont permettre de manipuler la liste chainée de tokens: 
----------------------------------------------------------------------*/

t_token	*ft_new_token(char *value, int type)
{
	t_token	*new;

	new = (t_token*)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = value;
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_token	*ft_lstlast_token(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_token(t_token **alst, t_token *new)
{
	t_token	*last;

	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	if (new != 0)
	{
		last = ft_lstlast_token(*alst);
		last->next = new;
	}
}

void    ft_print_token_list(t_token *token_list)
{
	int i;
	int	j;

	if (!token_list)
	{
		ft_printf("liste vide\n");
		return;
	}
	i= 1;
	while (token_list)
	{
		ft_printf("----------------------------\n");
		ft_printf("| value = [%s]", token_list->value);
		ft_printf("\n| type = %d\n", token_list->type);
		ft_printf("| next element = %p\n", token_list->next);
		ft_printf("----------------------------\n");
		ft_printf("              |             \n");
		ft_printf("              v             \n");
		token_list = token_list->next;
		i++;
	}
}  

// fct pour libérer toute la liste (free du premier maillon jusqu'au dernier) : lstclear
