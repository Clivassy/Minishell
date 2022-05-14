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

typedef struct s_elm
{
    char **cmd;
    int file_in;
    int file_out;
    struct s_elm *next;
}   t_elm;

typedef struct s_data
{
	int exit_asked;
    char *read_line;
    char **env;
    char **command_list;
    t_elm   *exec_list;
}	t_data;

// minishell_loop
void    ft_minishell_loop(t_data *env);



#endif