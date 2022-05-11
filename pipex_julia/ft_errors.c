/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:39:40 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/29 16:43:22 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/* Fd error */
void	ft_fd_error(char *file, char *error, t_pipex *input)
{
	ft_printf("Error: %s", error);
	ft_printf(": %s", file);
	ft_printf("\n");
	free(input);
	exit(EXIT_FAILURE);
}

/* Input error*/
void	ft_input_error(t_pipex *input)
{
	ft_printf("Wrong Input\nEx: ./pipex [file1][cmd1][cmd2][file2]\n");
	free(input);
	exit(EXIT_FAILURE);
}

/*Error with fd or dup or pipe*/
void	ft_error(t_pipex *input)
{
	perror("Error\n");
	free(input);
	exit(EXIT_FAILURE);
}

/* Cmd not found error */
void	ft_cmd_error(char **cmd, t_pipex *input)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": Command Not Found\n", 20);
	if (ft_strnstr(*cmd, "/", ft_strlen(*cmd)))
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	ft_free(cmd);
	free(input);
	exit(EXIT_FAILURE);
}
