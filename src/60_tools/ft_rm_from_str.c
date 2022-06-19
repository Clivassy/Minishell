#include "minishell.h"

void	ft_rm_from_str(t_data *data, char **s, int rm_len, int position)
{
	int		new_size;
	char	*new_s;
	int		i;
	int		j;

	new_size = ft_strlen(*s);
	new_s = ft_malloc(data, sizeof(char) * (new_size + 1));
	if (!new_s)
		ft_exit(data);
	if (position > ft_strlen(*s))
		position = ft_strlen(*s);
	i = 0;
	while (i < position)
	{
		new_s[i] = (*s)[i];
		i++;
	}
	j = i ;
	while ((*s)[j] && j - i < rm_len)
		j++;
	while ((*s)[j])
		new_s[i++] = (*s)[j++];
	new_s[i] = '\0';
	ft_free(data, *s);
	*s = new_s;
}
