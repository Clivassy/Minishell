#include "minishell.h"

/* -----------------------------------------------------------
remove variable from the env 
unset + variable || variables 
unset alone doesn't do anything 
1) recupérer l'env 
2) checker si la variable est présente dans l'env
3) supprimer la variable et sa value de l'env.
-----------------------------------------------------------*/

void    ft_rm_str_from_env(t_data *data, char *var)
{
    int     i;

    i = 0;
    while(data->env[i])
    {
        if(ft_strcmp(var, ft_env_get_key_on_line(data, data->env[i]))== 0)
        {
            printf("Variable on this line\n");
            printf("BEFORE EMOVAL =%s\n", data->env[i]);
            data->env[i] = '\0';
            free(data->env[i]);
            printf("AFTER REMOVAL =%s\n", data->env[i]);
        }
        i++;
    }
    ft_print_env(data->env);
   // printf("STRING =%s\n", &str);
}

int ft_unset_variable(t_data *data, char *var)
{

    printf("---PROCEED UNSET OF \"%s\" VARIABLE------\n", var);
  //  ft_print_env(new_env);
    ft_rm_str_from_env(data, var);

    // search the varibale in the env
    // => env_variable = get the variable
    //protection : if env_var == NULL => error
    // parcourir l'env jusqu'a trouvé le maillon avec la variable
    // et degager le maillon : removea a char* from a char**
    return(0);
    
}
/* return (1) if char is a valid identifier
return(0) if char isn't a valid char */
int ft_is_valid_identifier(char **cmd)
{
    int i;
    int j;

    i = 0;
    while(cmd[i])
    {
        j = 0;
        if(!ft_isalpha(cmd[i][j]))
            return(0);
        i++;
    }
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
        // determiner quels sont les "valid identifier"
        if (ft_is_valid_identifier(cmd))
        {
            is_in_env = ft_env_key_is_present(data, cmd[i]);
            if(is_in_env == 1)
                printf("La variable est présente dans l'environnement\n");
            ft_unset_variable(data, cmd[i]);
        }
        else
        {
            ft_printf("bash: unset: `%s': not a valid identifier\n",cmd[1]);
            data->last_pipeline_exit_status = 1;
            // printf(message d'erreur);
        }
        //printf("string = %s\n", cmd[i]);
        i++;
    }
    return (0);
    // check si il y a quelque chose après le unset : si aucun argument 
    // use ft_env_key_is_present : check si l'argument est present dans l'env
}

// l'env est stoké dans data->env ==  char**
void    ft_test_unset(t_data *data, char **envp, char **argv)
{
    //printf("cmd = %s\n", argv[1]);
    ft_dup_env(data, envp);
    ft_unset(data, &argv[1]);
    // print env 
}