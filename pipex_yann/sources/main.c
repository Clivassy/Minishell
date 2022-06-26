/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:35:03 by ybellot           #+#    #+#             */
/*   Updated: 2022/06/26 19:28:42 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile cmd1 cmd2 outfile
//   argv[] [1]   [2]   [3]   [4]
int	main(int argc, char **argv, char **envp)
{
	int		fd_pipe[2];
	pid_t	id_fork1;
	pid_t	id_fork2;

	if (argc != 5)
		ft_error("error, wrong number of argument");
	if (pipe(fd_pipe) == -1)
		ft_error("error opening pipe");
	id_fork1 = fork();
	if (id_fork1 < 0)
		ft_error("erreur fork1");
	if (id_fork1 == 0)
		ft_first_command(fd_pipe, argv, envp);
	id_fork2 = fork();
	if (id_fork2 < 0)
		ft_error("error fork2");
	if (id_fork2 == 0)
		ft_second_command(fd_pipe, argv, envp);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(id_fork1, NULL, 0);
	waitpid(id_fork2, NULL, 0);
	return (0);
}

void	ft_first_command(int *fd_pipe, char **argv, char **envp)
{
	int	fd_infile;

	if (close(fd_pipe[0]) == -1)
		ft_error("error closing pipe");
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile < 0)
		ft_error("error opening infile");
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		ft_error("error with stdin redirection");
	if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
		ft_error("error with stdout redirection");
	ft_launch_command(argv[2], envp);
}

void	ft_second_command(int *fd_pipe, char **argv, char **envp)
{
	int	fd_outfile;

	if (close(fd_pipe[1]) == -1)
		ft_error("error closing pipe");
	fd_outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
		ft_error("error opening outfile");
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
		ft_error("error with stdin redirection");
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		ft_error("error with stdout redirection");
	ft_launch_command(argv[3], envp);
}
