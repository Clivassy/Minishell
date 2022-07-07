#include "minishell.h"

t_token    *ft_simulation_token_1(t_token *heretag)
{
    heretag = malloc(sizeof(t_token));
    heretag->type = T_CMD;
    heretag->value = "end";

    printf("TOKEN VALUE : %s\n", heretag->value);
    printf("TOKEN TYPE : %d\n", heretag->type);

    return(heretag);
}

t_token    *ft_simulation_token_2(t_token *heretag)
{
    heretag = malloc(sizeof(t_token));
    heretag->type = T_CMD;
    heretag->value = "\"end\"";

    printf("TOKEN VALUE : %s\n", heretag->value);
    printf("TOKEN TYPE : %d\n", heretag->type);

    return(heretag);
}

t_token    *ft_simulation_token_3(t_token *heretag)
{
    heretag = malloc(sizeof(t_token));
    heretag->type = T_CMD;
    heretag->value = "\'end\'";

    printf("TOKEN VALUE : %s\n", heretag->value);
    printf("TOKEN TYPE : %d\n", heretag->type);

    return(heretag);
}