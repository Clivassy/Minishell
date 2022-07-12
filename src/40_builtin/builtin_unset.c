#include "minishell.h"

/* -----------------------------------------------------------
Descriptif : remove variable from the env 
-----------------------------------------------------------*/
void    ft_debeug(t_data *data, char *msg, char **env, char *color)
{
    ft_print_color(color);
    printf("--------------%s-----------\n", msg);
    ft_print_env(env);
    ft_print_color(COLOR_MAGENTA);
    printf("NUMBER = %d\n",ft_env_nb_of_lines(data->env));
}

void    ft_rm_str_from_env(t_data *data, char **new_env, char *var, int len)
{
    int i;
    int j;
    int status;

    status = 1;
   // ft_debeug(data, "BEFORE REMOVAL", data->env, COLOR_YELLOW);
    i = 0;
    j = 0;
    printf("LEN = %d\n", len);
    while(i < len)
    {
        if(ft_strcmp(var, ft_env_get_key_on_line(data, data->env[i])) == 0
        && status > 0)
        {
           /* ft_print_color(COLOR_RED);
            printf("FOUND = %s\n", var);
            printf("FOUND = %s\n", data->env[i]);*/
            status = -1;
            i++;
        }
        new_env[j] =  ft_strdup((const char *)data->env[i]);
		ft_add_to_garbage_collector(data, new_env[j]);
        i++;
        j++;
    }
    new_env[j] = NULL;
    data->env = new_env;
    //ft_debeug(data, "AFTER REMOVAL", data->env, COLOR_GREEN);
}

void    ft_unset_variable(t_data *data, char *var)
{
    char **new_env;
    int i;

    ft_print_color(COLOR_MAGENTA);
    printf("%d\n", ft_env_nb_of_lines(data->env));
    new_env = ft_malloc(data, sizeof(char *) * 
    (ft_env_nb_of_lines(data->env)));
    if(!new_env)
        ft_exit(data);
    i = 0;
    while (i < ft_env_nb_of_lines(data->env))
    {
        new_env[i] = NULL;
        i++;
    }
   // ft_print_color(COLOR_CYAN);
   // printf("\n---PROCEED UNSET OF \"%s\" VARIABLE------\n\n", var);
    ft_rm_str_from_env(data, new_env, var, ft_env_nb_of_lines(data->env));

}

/* return (1) if char is a valid identifier
return(0) if char isn't a valid char */
int ft_is_valid_identifier(char *cmd)
{
    int i;

    i = 0;
    if(!ft_isalpha(cmd[0]) && cmd[0] != '_')
            return(0);
    while (cmd[i])
    {
        if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
            return(0);
        i++;
    } 
    return(1);
}

int ft_builtin_unset(t_data *data, char **cmd)
{
    int i;
    int exit_code;
    int is_in_env;

    i = 1;
    exit_code = 0;
    is_in_env = 0;
    if (!cmd[1])
        return(0);
    while(cmd[i])
    {
        if (ft_is_valid_identifier(cmd[i]))
        {
            is_in_env = ft_env_key_is_present(data, cmd[i]);
            if(is_in_env == 1)
                ft_unset_variable(data, cmd[i]);
        }
        else
        {
           // ft_print_color(COLOR_NORMAL);
            ft_printf("bash: unset: `%s': not a valid identifier\n",cmd[i]);
            exit_code = 1;
        }
        i++;
    }
    return (exit_code);
}

/*
void    ft_test_unset(t_data *data, char **envp, char **argv)
{
   // ft_dup_env(data, envp);
    ft_builtin_unset(data, &argv[1]);

}*/