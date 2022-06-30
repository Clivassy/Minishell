#include "minishell.h"

void	create_exec_list_1(t_data *data)
{
	create_gp_token_list_1(data);
	ft_fill_exec_list_cmd__and_redirect(data);
	ft_printf("###### exec list testee ######\n");
	ft_print_color(COLOR_CYAN);
    ft_exec_elm_lst_print(data->exec_list);
	ft_print_color(COLOR_NORMAL);



}




    //char *command2[2]= {"cat",NULL};
    //elm_tmp = ft_exec_elm_ceate_new(pt_data, command2, 3, 4);
    //ft_lst_add(&(pt_data->exec_list), elm_tmp);

    //char *command3[3]= {"grep", "m",NULL};
    //elm_tmp = ft_exec_elm_ceate_new(pt_data, command3, 5, 6);
    //ft_lst_add(&(pt_data->exec_list), elm_tmp);

    //char *command4[2]= {"cat",NULL};
    //elm_tmp = ft_exec_elm_ceate_new(pt_data, command4, 7, 8);
    //ft_lst_add(&(pt_data->exec_list), elm_tmp);

    //// ft_lst_print(pt_data->exec_list);

    //// ------------------ lancement command -----------------------
    //ft_exec_command(pt_data);
