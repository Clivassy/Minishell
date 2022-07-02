#include "minishell.h"

void	ft_initialisation(t_data *data, char **envp)
{
	// a completer
	data->exit_asked = 0;
    data->read_line = NULL;
    data->env = NULL;
	data->last_pipeline_exit_status = 0;
	data->nb_of_process = 0;
    data->tokens_list = NULL;
    data->gp_tokens_list = NULL;
    data->exec_list = NULL;
	data->garbage_collector = NULL;

    ft_dup_env(data, envp);

}

void	ft_reinitialisation_read_data(t_data *data)
{
	// ajouter free dans aciennes allocations
    data->read_line = NULL;
	data->nb_of_process = 0;
    data->tokens_list = NULL;
    data->gp_tokens_list = NULL;
    data->exec_list = NULL;
}
