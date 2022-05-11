#ifndef MINISHELL_H
# define MINISHELL_H

# define COMMAND 0
# define PIPE 1
# define SIMPLE_INPUT_REDIRECT 2
# define DOUBLE_INPUT_REDIRECT 3
# define SIMPLE_OUTPUT_REDIRECT 4
# define DOUBLE_OUTPUT_REDIRECT 5

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_env
{
	int exit_asked;
    char *read_line;

}	t_env;

typedef struct s_elm
{
    int type;
    
    struct s_elm *next;




}   t_elm;
#endif