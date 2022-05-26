#include "minishell.h"

/* temporaire : return error */
void    ft_lexer_error(char *msg)
{
    ft_printf("%s\n", msg);
    exit(EXIT_FAILURE);
}