#include "minishell.h"
/*--------------------------------------------------------------------
Fonctions qui vont permettre de manipuler la liste chainée de tokens: 
----------------------------------------------------------------------*/

// fct pout créer un nouvel élément a la liste.
t_token	*token_new(char *value, int type)
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

// fct pour retourner le dernier élément de la liste 

// fct pour ajouter un élément à la fin de la liste 

// fct pour libérer toute la liste (free du premier maillon jusqu'au dernier)