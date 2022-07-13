#include "minishell.h"

// calcul la longueur d'un tableau tab termine par un NULL
// (sans compter le NULL a la fin)
// retourne 0 si tab = NULL
size_t	ft_null_terminated_tab_len(char **tab)
{
	size_t	size;

	if (!tab)
		return (0);
	size = 0;
	while (tab[size] != 0)
	{
		size++;
	}
	return (size);
}
