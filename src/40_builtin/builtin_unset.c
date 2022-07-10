#include "minishell.h"

/* -----------------------------------------------------------
remove variable from the env 
unset + variable || variables 
unset alone doesn't do anything 
1) recupérer l'env 
2) checker si la variable est présente dans l'env
3) supprimer la variable et sa value de l'env.
-----------------------------------------------------------*/
int ft_unset_variable(t_data *data, char *var)
{
    char *env_variable;

    // search the varibale in the env
    // => env_variable = get the variable
    //protection : if env_var == NULL => error
    // parcourir l'env jusqu'a trouvé le maillon avec la variable
    // et degager le maillon. 
    
}

int ft_unset(t_data *data, char **cmd)
{
    printf("cmd = %s\n", cmd[0]);
    int i;
    int is_in_env;

    i = 0;
    is_in_env = 0;
    if (!cmd[1])
        return(1);
    while(cmd[i])
    {
        is_in_env = ft_env_key_is_present(data, cmd[i]);
        if(is_in_env == 1)
        {
            printf("La variable est présente dans l'environnement\n");
            ft_unset_variable(data, cmd[1]);
        }
        else
        {
            // printf(message d'erreur);
        }
       // printf("string = %s\n", cmd[i]);
        i++;
    }
        return (0);
    // check si il y a quelque chose après le unset : si aucun argument 
    // use ft_env_key_is_present : check si l'argument est present dans l'env
}

// l'env est stoké dans data->env ==  char**
void    ft_test_unset(t_data *data, char **envp, char **argv)
{
    printf("cmd = %s\n", argv[1]);
    ft_dup_env(data, envp);
    ft_unset(data, &argv[1]);
    // print env 
}