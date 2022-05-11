/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichier_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:27:34 by ybellot           #+#    #+#             */
/*   Updated: 2022/03/16 11:08:06by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> //util ?
#include <string.h>
#include <errno.h>
#include <time.h>


void ft_error(char *str);

void	fonction_test_fork()
{
	fork();
	printf("print dans fct\n");
}


int main(int argc, char **argv, char **envp)
{
	int fd_pipe[2];
	pid_t id_fork1;
	pid_t id_fork2;

	if(pipe(fd_pipe) == -1)
		ft_error("error opening pipe");
	id_fork1 = fork();
	if (id_fork1 < 0)
		ft_error("erreur fork1");
	else if (id_fork1 == 0)
	{
		printf("start process child1, idfork = %d\n", id_fork1);
		sleep(1);
	}
	else
	{
		id_fork2 = fork();
		if (id_fork2 < 0)
			ft_error("error fork2");
		else if (id_fork2 == 0)
		{
			printf("start process child2, idfork = %d\n", id_fork2);
			sleep(3);
		}
		else
		{
			printf("debut wait id_fork1\n");
			waitpid(id_fork1, NULL, 0);
			printf("debut wait id_fork2\n");
			waitpid(id_fork2, NULL, 0);
		}
	}

	printf("fin processus id_fork1:%d id_fork2:%d\n", id_fork1, id_fork2);
	return(0);
}

int main2()
{

    pid_t pid1;
    pid_t pid2;
    pid_t pid_courant;
    pid_t pid_parent;

	pid_courant = getpid();
	printf("pid courant ini = %d\n", pid_parent);
    pid1 = fork();
    // pid2 = fork();
	if (pid1 == 0)
	{
		// child process
		pid_courant = getpid();
		pid_parent = getppid();
		printf("child : pid_courant = %d    pid_parent = %d      pid1 = %d\n",pid_courant, pid_parent, pid1);
		sleep(2);

	}
	else
	{
		// parennt process
		printf("avant wait\n");
		waitpid(pid1, NULL, 0);
		pid_courant = getpid();
		pid_parent = getppid();
		printf("parent : pid_courant = %d    pid_parent = %d      pid1 = %d\n",pid_courant, pid_parent, pid1);

	}



    return 0;
}
//clear && gcc fichier_tests.c && ./a.out

int main1(int argc, char **argv, char **envp)
{
	int arr[] = {1, 2, 3, 4, 1, 2};
	int start, end;
	int fd[2];
	pipe(fd);

	// int id = fork();


		// child
		int a = 42;
		int c = 12;
		// close(fd[0]);
		// printf("test lecture : %p\n", &a);
		// write(1, &a, sizeof(a));
		write(fd[0], &a, sizeof(a));
		// write(fd[1], &c, sizeof(c));

		int b;
		// close(fd[1]);
		// read(fd[0], &b, sizeof(b));
		read(fd[1], &b, sizeof(b));
		// printf("test lecture : %d\n", b);
		fonction_test_fork();
		printf("exec apres fct test fork\n");

	int i = 0;
	while (envp[i] && 0)
	{
		printf("%s\n", envp[i]);
		i++;

	}

}
void ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
/* commande tests
clear && gcc fichier_tests.c && ./a.out
*/
