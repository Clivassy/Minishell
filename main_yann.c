#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	ft_printf(" ################## DEBUT PROGRAM  ##########################\n");

    t_data data;
	ft_initialisation(&data, envp);

	// creation env
    ft_dup_env(&data, envp);
	//ft_print_env(data.env);

    //ft_test_echo();
	//char *tmp[2] = {"ls",NULL};
	//chdir("/mnt/nfs/homes/ybellot/");
	//execve("/usr/bin/ls",tmp , envp);

	// test cd
	//ft_cd(NULL);

	// test garbagge collector
	//ft_test_garbage_collector(&data);

	//test env
	//ft_test_env(&data);

	// test add to str
	//ft_test_add_to_str(&data);
	//ft_test_add_to_str_end(&data);

	//test rm from str
	//ft_test_rm_from_str(&data);

	// test expand
	//create_token_list_1(&data);
	//ft_test_expand_token(&data);
	//ft_test_expand(&data);

	// test rm quotes from token
	//create_token_list_2(&data);
	//ft_test_rm_quotes_in_token(&data);
	//ft_test_rm_quotes_in_token_list(&data);

	//test exec_list_creation
	//ft_test_exec_list_creation(&data);

	//test read_gp_token_to_fill_exec_list
	//ft_test_ft_set_exec_t_redirect_in(&data);

	//test command execution
	ft_test_command_execution(&data);
	
	//test print error
	ft_print_error(&data, SYNTAX_ERR_PIPE);

	ft_free_garbage_collector(&data);
    return(0);
}

int main_exec()
{


    //// ------------------ Creation exec_list -----------------------
    //t_data data;
    //t_data *pt_data = &data;
    //t_exec_elm *elm_tmp;

    //pt_data->exit_asked = 0;
    //pt_data->read_line = NULL;
    //pt_data->env = NULL;
    ////pt_data->command_list = NULL;
    //pt_data->exec_list = NULL;

    //char *command1[3]= {"ls","-la",NULL};
    //elm_tmp = ft_exec_elm_ceate_new(pt_data, command1, 1, 2);
    //ft_lst_add(&(pt_data->exec_list), elm_tmp);

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
    //ft_exec_cmd(pt_data);
    return (0);
}
