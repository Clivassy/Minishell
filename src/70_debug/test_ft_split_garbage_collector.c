#include "minishell.h"

void	ft_test_split_garbage_collector(t_data *data)
{
	char **str = ft_split_garbage_collector(data, "chaine a:split:enplusieurs:", ':');
	printf("verif split\n");
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);

	ft_free_split_garbage_collector(data, str);
	// lignes suivantes devraient segfault ou afficher d'autres choses car free
	//	printf("verif split\n");
	//printf("%s\n", str[0]);
	//printf("%s\n", str[1]);
	//printf("%s\n", str[2]);
	//printf("%s\n", str[3]);
}
