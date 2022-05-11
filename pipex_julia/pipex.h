/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:48:33 by jbatoro           #+#    #+#             */
/*   Updated: 2022/03/29 17:06:00 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef PATH
#  define PATH "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin: \
				/usr/local/go/bin:/usr/local/munki"
# endif

# include "./ft_printf/libftprintf.h"
# include <time.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
	int		fd_pipe[2];
	int		first_fd;
	int		second_fd;
	int		pid_1;
	int		pid_2;
	char	*cmd;
	char	**cmd1_arg;
	char	**cmd2_arg;
	char	**paths;
	char	**env;
}		t_pipex;

int		main(int argc, char **argv, char **env);

/* Parsing */
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_get_paths(t_pipex *input);
char	*ft_check_one_path(t_pipex *input, int index);
void	ft_free(char **args);
size_t	ft_strlen(const char *s);

/*Errors*/
void	ft_cmd_error(char **cmd, t_pipex *input);
void	ft_fd_error(char *file, char *error, t_pipex *input);
void	ft_error(t_pipex *input);
void	ft_input_error(t_pipex *input);

/* utils*/
void	ft_close_pipes(t_pipex *input);
void	ft_close_fds(t_pipex *input);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
