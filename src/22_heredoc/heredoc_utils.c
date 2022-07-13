#include "minishell.h"

void	ft_wait_pid_heredoc(int id, t_data *data)
{
	int	return_status;

	return_status = -1;
    waitpid(id, &return_status, 0);
    if(WIFEXITED(return_status))
	{
		data->last_pipeline_exit_status = WEXITSTATUS(return_status);
	}
	else
		data->last_pipeline_exit_status = return_status;
}

int ft_is_quoted(char *heretag)
{
    if (!ft_strchr(heretag, '\'') && !ft_strchr(heretag, '\"'))
        return(1);
    return(0);
}

int ft_is_expand_required(char *heretag)
{
    if (ft_strchr(heretag, '$'))
        return (1);
    return (0);
}

/*
void ft_test(int file[2])
{
    char buf[4096];
    char *read_p;

    read_p = read(file[0], buf, 4096);
    printf("BUFFER = %s\n", buf);
}*/