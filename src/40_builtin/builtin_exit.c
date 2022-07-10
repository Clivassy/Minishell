#include "minishell.h"

int	ft_builtin_exit(t_data *data)
{
	if (data->nb_of_process == 1)
		write(2, "exit\n", 5);
	ft_free_garbage_collector(data);
    exit(0);
	// changer code erreur en fct nb arguments, pas besoin de modifier
	// data->last_pipeline_exit_status car le exit renvoie le code direct
	// ajout liberation des FD
}
