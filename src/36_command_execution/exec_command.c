#include "minishell.h"

// called whith current_index < 0 will close all the fd
void	ft_close_fd_exept_current(t_data *data, int current_index)
{
	t_exec_elm *exec_elm;
	while(exec_elm)
	{
		if (exec_elm->index != current_index)
			{
				close(exec_elm->fd_in); // ajouter protection fct
				close(exec_elm->fd_out); // ajouter protection fct
			}
		exec_elm = exec_elm->next;
	}
}

void    ft_launch_processus(t_data *data, t_exec_elm *exec_elm)
{
	ft_printf("lancement processus, index: %d, pid %d\n", exec_elm->index, exec_elm->pid);
    pid_t id;
    id = fork();

	exit(0); // voir comment exit le processus quand on saura pour les codes erreur

}

void    ft_exec_command(t_data *data)
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

	int index;
	t_exec_elm *exec_elm;
	pid_t id;

	index = 0;
	exec_elm = data->exec_list;
	while(exec_elm)
	{
		id = fork();
		if (id == 0)
		{
			ft_close_fd_exept_current(data, index);
			ft_launch_processus(data, exec_elm);
		}
		exec_elm = exec_elm->next;
	}
	//fork();
}


