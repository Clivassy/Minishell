/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:00:02 by ybellot           #+#    #+#             */
/*   Updated: 2022/03/18 20:43:45 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <errno.h>
# include <fcntl.h>

// main.c
void	ft_first_command(int *fd_pipe, char **argv, char **envp);
void	ft_second_command(int *fd_pipe, char **argv, char **envp);

// exec command
void	ft_launch_command(char *cmd, char **envp);
void	ft_launch_command_child_old(char *cmd, char **envp);
char	*ft_find_command(char *cmd, char **envp);
char	*ft_check_path_command(char **paths, char *cmd);

// error
void	ft_error(char *str);

// libft tools
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
size_t	ft_strlen(char *str);
void	ft_free_pointer_array(char **array);

#endif
