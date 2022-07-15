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

// ne gere pas les string NULL
void	ft_add_to_str(t_data *data, char **str, char *to_add, int position)
{
	int		new_size;
	char	*new_str;

	if (!to_add | !str | !*str)
		return ;
	new_size = ft_strlen(*str) + ft_strlen(to_add);
	new_str = ft_malloc(data, sizeof(char) * (new_size + 1));
	if (!new_str)
		ft_exit(data);
	if (position > (int)ft_strlen(*str))
		position = (int)ft_strlen(*str);
	ft_ats_copy_str(position, str, new_str, to_add);
	ft_free(data, *str);
	*str = new_str;
}

// ne gere pas les string NULL
void	ft_add_to_str_end(t_data *data, char **str, char *to_add)
{
	int		new_size;
	char	*new_str;
	int		position;

	if (!to_add | !str | !*str)
		return ;
	new_size = ft_strlen(*str) + ft_strlen(to_add);
	new_str = ft_malloc(data, sizeof(char) * (new_size + 1));
	if (!new_str)
		ft_exit(data);
	position = ft_strlen(*str);
	ft_ats_copy_str(position, str, new_str, to_add);
	ft_free(data, *str);
	*str = new_str;
}
