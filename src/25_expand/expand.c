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
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	ft_word_size(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '$' && str[i])
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

// bug a fix : taille avec key dans env pas bonne
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
			i++;
			word = ft_get_word_for_expand(data, &str[i]);
			ft_printf("word: %s \n", word);
			if (ft_env_key_is_present(data, word))
			{

				ft_printf("key trouvee: %s \n", word);
				ft_printf("len mot: %d \n", ft_strlen(ft_env_get_value(data, word)));
				ft_printf("count avant: %d \n", count);
				count += ft_strlen(ft_env_get_value(data, word));
				ft_printf("count apres: %d \n", count);
				i += ft_strlen(ft_env_get_value(data, word));
				ft_printf("i:%d, str[i] = %c \n",i, str[i]);
				ft_printf("len: %zu \n", ft_strlen(word));
			}
			else
			{
				printf("key non trouvee: %s \n", word);
				count += 1 + ft_strlen(&str[i]); // 1 pour compter le $
				i += ft_strlen(word);
				ft_printf("i:%d, str[i] = %c \n",i, str[i]);

			}
			//in_word = 1;
			//while (str[i] != ' ' && str[i] != '\0')
			//{
			//	ft_printf("i:%d, str[i] = %c \n",i, str[i]);
			//	i++;
			//}
		}
		else if (str[i] == ' ')
		{
			i++;
			count++;
			ft_printf("count add space: str[i]=%c \n", str[i]);

		}
		else
		{
			while (str[i] != ' ' && str[i] != '$' && str[i])
			{
				i++;
				count++;
				ft_printf("count add trim: str[i]=%c \n", str[i]);
			}
		}
		i++;
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
