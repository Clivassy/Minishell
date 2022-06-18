#include "minishell.h"

static void	ft_ats_copy_str(int position, char **s, char *new_s, char *to_add)
{
	int		i;
	int		j;

	i = 0;
	while (i < position)
	{
		new_s[i] = (*s)[i];
		i++;
	}
	j = i;
	while (*to_add)
	{
		new_s[i] = *to_add;
		to_add++;
		i++;
	}
	while ((*s)[j])
	{
		new_s[i] = (*s)[j];
		i++;
		j++;
	}
	new_s[i] = '\0';
}

// ajoute
void	ft_add_to_str(t_data *data, char **str, char *to_add, int position)
{
	int		new_size;
	char	*new_str;

	new_size = ft_strlen(*str) + ft_strlen(to_add);
	new_str = ft_malloc(data, sizeof(char) * (new_size + 1));
	if (position > ft_strlen(*str))
		position = ft_strlen(*str);
	if (!new_str)
		ft_exit(data);
	ft_ats_copy_str(position, str, new_str, to_add);
	ft_free(data, *str);
	*str = new_str;
}
