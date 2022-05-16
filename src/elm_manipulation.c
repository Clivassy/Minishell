#include "minishell.h"

t_elm	*ft_elm_ceate_new(t_data *data, char **cmd, int fd_in, int fd_out)
{
    t_elm  *new_elm;

    new_elm = (t_elm *)malloc(sizeof(new_elm));
    new_elm->cmd = cmd;
    if (!new_elm)
        ft_exit(data);
    new_elm->fd_in = fd_in;
    new_elm->fd_out = fd_out;
    new_elm->next = NULL;
    return (new_elm);

}