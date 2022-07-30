/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:29:00 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/15 21:21:19 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 0)
		return (NULL);
	if (buf[fd] == NULL)
		ft_initbuffer(buf[fd]);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	return (ft_gnl_algo(fd, &buf[fd], &line));
}

char	*ft_gnl_algo(int fd, char (*buf)[BUFFER_SIZE], char **line)
{
	ssize_t		nb_read;

	nb_read = BUFFER_SIZE;
	while (!ft_has_eol(*buf) && nb_read == BUFFER_SIZE)
	{
		ft_translat_buffer(*buf, ft_cpy_bufftoline(line, *buf));
		nb_read = read(fd, *buf, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(*line);
			return (NULL);
		}
	}
	ft_translat_buffer(*buf, ft_cpy_bufftoline(line, *buf));
	if (nb_read != BUFFER_SIZE && *buf[0] == 0 && *line[0] == 0)
	{
		free(*line);
		return (NULL);
	}
	return (*line);
}

int	ft_cpy_bufftoline(char **line, char *buff)
{
	char	*new;
	int		translated_size;

	if (*line == NULL || buff == NULL)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen(*line) + BUFFER_SIZE + 1));
	if (!new)
		return (0);
	translated_size = ft_cpy_line_and_buff(new, *line, buff);
	free(*line);
	*line = new;
	return (translated_size);
}

int	ft_cpy_line_and_buff(char *new, char *line, char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		new[i] = line[i];
		i++;
	}
	j = 0;
	while (j < BUFFER_SIZE && buff[j] && buff[j] != '\n')
	{
		new[i + j] = buff[j];
		j++;
	}
	if (j < BUFFER_SIZE && buff[j] == '\n')
	{
		new[i + j] = '\n';
		new[i + j + 1] = 0;
	}
	else
		new[i + j] = 0;
	return (j + 1);
}

void	ft_translat_buffer(char *buf, int nb)
{
	int	i;

	if (nb > BUFFER_SIZE)
	{
		ft_initbuffer(buf);
		return ;
	}
	i = 0;
	while (i + nb < BUFFER_SIZE)
	{
		buf[i] = buf[i + nb];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}
