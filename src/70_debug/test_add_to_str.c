#include "minishell.h"

void	ft_test_add_to_str(t_data *data)
{
	char *to_add = "1234";
	char *str = ft_malloc(data, 5);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = '\0';

	ft_printf("str avant add : %s\n", str);
	ft_add_to_str(data, &str, to_add, 2);
	ft_printf("str apres add : %s\n", str);

}
