#include "minishell.h"

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

    fork();
}

void    ft_launch_processus(t_data *data, int index)
{
    pid_t id;
    id = fork();

}