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
/* ft_put_var_into_env 
- passer la string en parametre
- check si null ou si pas de  = 
- la logique : 
j'alloue la place pour la taille de l'env + 2 (null + new_var)
+ je copie l'env dans le nouvel env avec la nouvelle variable et sa value. 
*/

void    ft_add_var_to_env(t_data *data, char **new_env, char *var)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < ft_env_nb_of_lines(data->env))
    {
        new_env[j] =  ft_strdup((const char *)data->env[i]);
		ft_add_to_garbage_collector(data, new_env[j]);
        i++;
        j++;
    }
    new_env[j] = ft_strdup(var);
    ft_add_to_garbage_collector(data, new_env[j]);
    ft_free(data, data->env);
    data->env = new_env;
    ft_debeug(data, "AFTER REMOVAL", data->env, COLOR_GREEN);
}

int ft_is_arg_ok(t_data *data, char *cmd)
{
    int i;
    char *new_var;
    
    //printf("STRING= \'%s\'", cmd);
    if(!ft_strchr(cmd, '='))
        return(0);
    i = 0;
    new_var = ft_env_get_key_on_line(data, &cmd[i]);
    if (ft_is_valid_identifier(new_var))
            return(1);
    return(0);
}

void    ft_create_new_env(t_data *data, char *var)
{
    char **new_env;
    int i;
    int len = ft_env_nb_of_lines(data->env) + 2;

    new_env = ft_calloc(len, sizeof(char *));
    ft_add_to_garbage_collector(data, new_env);
    ft_print_color(COLOR_YELLOW);
    i = 0;
    while (i < ft_env_nb_of_lines(data->env))
    {
        new_env[i] = NULL;
        i++;
    }
    ft_print_color(COLOR_CYAN);
    printf("\n---PROCEED EXPORT OF \"%s\" VARIABLE------\n\n", var);
    ft_debeug(data, "BEFORE REMOVAL", data->env, COLOR_YELLOW);
    ft_add_var_to_env(data, new_env, var);
}

int ft_export(t_data *data, char **cmd)
{
    //printf("cmd = %s\n", cmd[0]);
    int i;
    int exit_code;

    exit_code = 0;
    i = 1;
    if (!cmd[1])
    {
        printf("No argument after commande unset\n");
        return (0);
    }
    while(cmd[i])
    {
         //printf("STRING= \'%s\'", cmd[i]);
        if (ft_is_arg_ok(data, cmd[i]))
        {
            ft_print_color(COLOR_GREEN);
            printf("--------Input is valid-------------\n");
            ft_create_new_env(data, cmd[i]);
        }
        else
        {
            ft_printf("bash: unset: `%s': not a valid identifier\n",cmd[i]);
            exit_code = 1;
        }
        i++;
    }
    return (exit_code);
}

void    ft_test_export(t_data *data, char **envp, char **argv)
{
    printf("cmd = %s\n", argv[1]);
    ft_export(data, &argv[1]);
}