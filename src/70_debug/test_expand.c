
#include "minishell.h"

void	ft_expand(t_data *data)
{
	int size = ft_size_after_expand(data, "chai");
	printf("size1: %d\n", size);

	size = ft_size_after_expand(data, "$test");
	printf("size2: %d\n", size);

	// revoir comptage taille mot et algo
	// tester mot vide


}
