#include "minishell.h"

/* -----------------------------------------------------------
Descriptif : remove variable from the env 
-----------------------------------------------------------*/

char *ft_get_var_in_env(t_data *data, char *var)
{
	char	*copy_line;
	int		i;

	copy_line = ft_strdup((const char *)var);
	if (!copy_line)
		ft_exit(data);
	i = 0;
	while (copy_line[i] && copy_line[i] != '=')
	{
		i++;
	}
	if (copy_line[i] == '=')
	{
		copy_line[i] = '\0';
		return(copy_line);
	}
	else
		return (NULL);
}
void    ft_rm_str_from_env(t_data *data, char *var)
{
    int     i;
    char **new_env;
    
    char *stock;
    int delimit = 1;
    stock = var;
    ft_print_color(COLOR_YELLOW);
    printf("--------------BEFORE REMOVAL-----------\n");
    ft_print_env(data->env);
    new_env = ft_malloc(data, sizeof(char *) * (ft_env_nb_of_lines(data->env)));
    if(!new_env)
        ft_exit(data);
    i = 0;
    while (i < ft_env_nb_of_lines(data->env))
    {
        new_env[i] = NULL;
        i++;
    }
    i = 0;
    while(data->env[i])
    {
        if(ft_strcmp(stock, ft_get_var_in_env(data, data->env[i])) == 0
        && delimit > 0)
        {
            ft_print_color(COLOR_RED);
            printf("FOUND = %s\n", stock);
            printf("FOUND = %s\n", data->env[i]);
            delimit = -1;
            free(data->env[i]);
        }
        new_env[i] =  ft_strdup((const char *)data->env[i]);
		ft_add_to_garbage_collector(data, new_env[i]);
        i++;
    }
    ft_print_color(COLOR_GREEN);
    printf("--------------AFTER REMOVAL-----------\n");
    ft_print_env(data->env);
}

int ft_unset_variable(t_data *data, char *var)
{
    ft_print_color(COLOR_YELLOW);
    printf("\n---PROCEED UNSET OF \"%s\" VARIABLE------\n\n", var);
    ft_rm_str_from_env(data, var);
    return(0);
}

/* return (1) if char is a valid identifier
return(0) if char isn't a valid char */
static int ft_is_valid_identifier(char *cmd)
{
    if(!ft_isalpha(cmd[0]))
            return(0);
    return(1);
}

/* exit satus = 0*/
int ft_unset(t_data *data, char **cmd)
{
    //printf("cmd = %s\n", cmd[0]);
    int i;
    int is_in_env;

    i = 1;
    is_in_env = 0;
    if (!cmd[1])
    {
        printf("No argument after commande unset\n");
        // il faudrait que je puisse quitter avec le bon code exit
        // la fct exit prend en compte le exit status code ??
        data->last_pipeline_exit_status = 0;
        ft_exit(data);
    }
    while(cmd[i])
    {
        // determiner quels sont les "valid identifier" : 
        // seems to be tout ce qui n'est pas alphanumerique
        if (ft_is_valid_identifier(cmd[i]))
        {
            is_in_env = ft_env_key_is_present(data, cmd[i]);
            if(is_in_env == 1)
                printf("La variable est présente dans l'environnement\n");
            ft_unset_variable(data, cmd[i]);
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

void    ft_test_unset(t_data *data, char **envp, char **argv)
{
    //printf("cmd = %s\n", argv[1]);
    ft_dup_env(data, envp);
    ft_unset(data, &argv[1]);
}