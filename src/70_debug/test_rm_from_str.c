#include "minishell.h"

void	ft_test_rm_from_str(t_data *data)
{
	int rm_len = 2;
	char *str = ft_malloc(data, 5);
	int position = 2;
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = '\0';
	// str: "a b c d \0"
	// pos:  0 1 2 3 4
	// len = 4

	ft_printf("str avant rm : %s\n", str);
	ft_rm_from_str(data, &str, rm_len, position);
	ft_printf("str apres rm : %s\n", str);

	// autres tests faits
	ft_rm_from_str(data, &str, 8, 0);
	ft_rm_from_str(data, &str, 8, 2);
	ft_rm_from_str(data, &str, 8, 8);

	ft_rm_from_str(data, &str, 2, 0);
	ft_rm_from_str(data, &str, 2, 2);
	ft_rm_from_str(data, &str, 2, 8);

	ft_rm_from_str(data, &str, 0, 0);
	ft_rm_from_str(data, &str, 0, 2);
	ft_rm_from_str(data, &str, 0, 8);








}
