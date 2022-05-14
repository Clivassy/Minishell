#include "minishell.h"

t_elm	*ft_elm_ceate_new(t_data *data, char **cmd, int file_in, int file_out)
{
    t_elm  *new_elm;

    new_elm = (t_elm *)malloc(sizeof(new_elm));
    new_elm->cmd = cmd;
    if (!new_elm)
        ft_exit(data);
    new_elm->file_in = file_in;
    new_elm->file_out = file_out;
    new_elm->next = NULL;
    return (new_elm);

}