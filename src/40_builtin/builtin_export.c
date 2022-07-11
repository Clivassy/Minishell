#include "minishell.h"

/* -----------------------------------------------------------
Descriptif : Set one variable and its value to env
Input format : export [variable]=[value]
If input format != [variable]=[value] 
    then : print error : bash: unset: ': not a valid identifier. 
    (exit code == 1)
else
    Proceed export
-----------------------------------------------------------------*/
static int ft_is_valid_identifier(char *cmd)
{
    int i;
    char *new_var;

    i = 0;
	while (cmd[i])
	{
        if (cmd[i] == '=')
        {
              
        }
            return(1);
		i++;
	}
    return (0);
    //checker syntaxe de la cmd
    //[variable]=[value] 
}

void    ft_add_var_to_env(t_data *data, char *var)
{
    ft_print_color(COLOR_YELLOW);
    printf("\n---PROCEED EXPORT OF \"%s\" VARIABLE------\n\n", var);
}

int ft_export(t_data *data, char **cmd)
{
    //printf("cmd = %s\n", cmd[0]);
    int i;

    i = 1;
    if (!cmd[1])
    {
        printf("No argument after commande unset\n");
        data->last_pipeline_exit_status = 0;
        ft_exit(data);
    }
    while(cmd[i])
    {
        if (ft_is_valid_identifier(cmd[i]))
        {
            ft_print_color(COLOR_GREEN);
            printf("--------Input is valid-------------\n");
            ft_add_var_to_env(data, cmd[i]);
        }
        else
        {
            ft_printf("bash: unset: `%s': not a valid identifier\n",cmd[i]);
            data->last_pipeline_exit_status = 1;
        }
        i++;
    }
    data->last_pipeline_exit_status = 0;
    return (0);
}

void    ft_test_export(t_data *data, char **envp, char **argv)
{
    //printf("cmd = %s\n", argv[1]);
    ft_dup_env(data, envp);
    ft_export(data, &argv[1]);
}