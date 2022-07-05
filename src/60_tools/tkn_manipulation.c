#include "minishell.h"
/*--------------------------------------------------------------------
Fonctions qui vont permettre de manipuler la liste chainée de tokens:
----------------------------------------------------------------------*/

t_token	*ft_new_token(t_data *data, char *value, int type)
{
	t_token	*new;

	new = (t_token*)ft_malloc(data, sizeof(t_token));
	if (!new)
		ft_exit(data);
	new->value = value;
	new->type = type;
	new->next = NULL;
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