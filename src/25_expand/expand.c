#include "minishell.h"

char	*ft_get_word_for_expand(t_data *data, char *str)
{
	int	i;
	int word_size;
	char *word;
	word_size = ft_word_size(data, str);
	word = ft_malloc(data, sizeof(char) * (word_size + 1));
	if (!word)
		ft_exit(data);
	i = 0;
	while (i < word_size)
		i++;
	word[i] = '\0';
	return (word);
}

int	ft_word_size(t_data *data, char *str)
{
	int	i;

	i = 0;
	// revoir cette condition
	while (str[i] != ' ' && (str[i] != '$' && i != 1) && str[i])
		i++;
	return (i);
}

int	ft_word_size_after_expand(t_data *data, char *word)
{
	int	len;

	len = 0;
	if (word[len] != '$')
	{
		while (word[len])
			len++;
	}
	else
	{
		if (ft_env_key_is_present(data, &word[1]))
		{
			len += ft_strlen(ft_env_get_value(data, &word[1]));
		}
		else
		{
			while (word[len])
				len++;
		}
	}
	return (len);
}

int	ft_size_after_expand(t_data *data, char *str)
{
	int	i;
	int	count;
	int	in_word;
	char *word;

	i = 0;
	count = 0;
	in_word = 0;
	while(str[i])
	{
		if (str[i] == '$')
		{
			word = ft_get_word_for_expand(data, &str[i]);
			i++;
			count++;
			if (ft_env_key_is_present(data, word))
			{
				printf("key trouvee: %s \n", word);
				count += ft_strlen(ft_env_get_value(data, word));
			}
			else
			{
				count += 1 + ft_strlen(&str[i]);
			}
			in_word = 1;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
		else if (str[i] == ' ')
		{
			i++;
			count++;
		}
		else
		{
			while (str[i] != ' ' && str[i] != '$' && str[i])
			{
				i++;
				count++;
			}
		}
	}
	return (count);
}
//int	ft_size_after_expand(t_data *data, char *str)
//{
//	int	i;
//	int	count;
//	int	in_word;
//	char *word;

//	i = 0;
//	count = 0;
//	in_word = 0;
//	while(str[i])
//	{
//		if (str[i] != '$' && str[i] != '\0' && in_word == 0)
//		{
//			i++;
//			count++;
//		}
//		else if (str[i] == '$')
//		{
//			i++;
//			count++;
//			word = ft_get_word(data, &str[i]);
//			if (ft_env_key_is_present(data, word))
//			{
//				count += ft_strlen(ft_env_get_value(data, word));
//			}
//			else
//			{
//				//while ()
//			}
//			in_word = 1;
//			while (str[i] != ' ' && str[i] != '\0')
//				i++;

//		}
//	}
//}
