#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_data data;
    data.env = NULL;
    dup_env(&data, envp);
    return(0);
}

int main_exec()
{


    // ------------------ Creation exec_list -----------------------
    t_data data;
    t_data *pt_data = &data;
    t_elm *elm_tmp;

    pt_data->exit_asked = 0;
    pt_data->read_line = NULL;
    pt_data->env = NULL;
    pt_data->command_list = NULL;
    pt_data->exec_list = NULL;

    char *command1[3]= {"ls","-la",NULL};
    elm_tmp = ft_elm_ceate_new(pt_data, command1, 1, 2);
    ft_lst_add(&(pt_data->exec_list), elm_tmp);

    char *command2[2]= {"cat",NULL};
    elm_tmp = ft_elm_ceate_new(pt_data, command2, 3, 4);
    ft_lst_add(&(pt_data->exec_list), elm_tmp);

    char *command3[3]= {"grep", "m",NULL};
    elm_tmp = ft_elm_ceate_new(pt_data, command3, 5, 6);
    ft_lst_add(&(pt_data->exec_list), elm_tmp);
    
    char *command4[2]= {"cat",NULL};
    elm_tmp = ft_elm_ceate_new(pt_data, command4, 7, 8);
    ft_lst_add(&(pt_data->exec_list), elm_tmp);

    // ft_lst_print(pt_data->exec_list);

    // ------------------ lancement command -----------------------
    ft_exec_command(pt_data);
    return (0);
}