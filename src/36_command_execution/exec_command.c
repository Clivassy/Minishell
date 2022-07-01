#include "minishell.h"

// called whith current_index < 0 will close all the fd
void	ft_close_fd_exept_current(t_data *data, int current_index)
{
	t_exec_elm *exec_elm;

	exec_elm = data->exec_list;
	while(exec_elm)
	{
		if (exec_elm->index != current_index)
			{
				if (exec_elm->fd_in != STDIN_FILENO)
				{
					ft_printf("index:%d, close fd: %d\n", current_index, exec_elm->fd_in);
					close(exec_elm->fd_in); // ajouter protection fct
				}
				if (exec_elm->fd_out != STDOUT_FILENO)
				{
					ft_printf("index:%d, close fd: %d\n", current_index, exec_elm->fd_out);

					close(exec_elm->fd_out); // ajouter protection fct
				}
			}
		exec_elm = exec_elm->next;
	}
}

void    ft_launch_processus(t_data *data, t_exec_elm *exec_elm)
{
	ft_printf("lancement processus, index: %d, pid %d\n", exec_elm->index, exec_elm->pid);
	ft_printf("fd_in: %d, fd_out: %d\n", exec_elm->fd_in, exec_elm->fd_out);

	if (exec_elm->fd_in != STDIN_FILENO)
	{
		if (dup2(exec_elm->fd_in, STDIN_FILENO) == -1)
			ft_exit(data); // revoir gestion erreur
	}
	if (exec_elm->fd_out != STDOUT_FILENO)
	{
		if (dup2(exec_elm->fd_out, STDOUT_FILENO) == -1)
						ft_exit(data); // revoir gestion erreur
	}
	ft_launch_command(exec_elm->cmd, data->env);

	sleep(3);

	exit(0); // voir comment exit le processus quand on saura pour les codes erreur

}

void    ft_exec_cmd(t_data *data)
{
    // boucle sur la list chainee des commandes a executer exec_list
    //      fork()
    //      fermer les pipe de toutes les autre commands
    //      si la command est possible (check dans buildin et dans chemin du path)
    //          lancer commande
    //          fermeture pipes ouverts ?
    //          exit du fork par la commande (automatique)
    //      sinon
    //          fermeture pipe
    //          exit processus
    // fermeture de tous les pipes dans le main
    // wait de tous les processus lances
    // exit

	int curent_index;
	t_exec_elm *exec_elm;
	pid_t id;

	curent_index = 0;
	exec_elm = data->exec_list;
	while(exec_elm)
	{
		id = fork(); // ajouter protection fork
		if (id == 0)
		{
			ft_close_fd_exept_current(data, curent_index);
			ft_launch_processus(data, exec_elm);
		}
		else
			exec_elm->pid = id;
		sleep(1);
		curent_index++;
		exec_elm = exec_elm->next;
	}
	ft_close_fd_exept_current(data, -1);

	exec_elm = data->exec_list;
	while(exec_elm)
	{
		ft_printf("attente fin processus: %d\n", exec_elm->index);
		waitpid(exec_elm->pid, NULL, 0); // remplacer NULL pour avoir l'id status
		exec_elm = exec_elm->next;
	}

	//fork();
}


