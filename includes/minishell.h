#ifndef MINISHELL_H
# define MINISHELL_H

/* Define TOKENS */
# define    PIPE 1
# define    DOLLARS 2
# define    REDIRECT_IN 3
# define    REDIRECT_OUT 4
# define    HEREDOC 5
# define    D_REDIRECT_OUT 6
# define    S_QUOTE 7
# define    D_QUOTE 8
# define    SPACE 9
# define    WORD 10

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_token
{
    int type;
    char *value;
    struct s_token *next;

}   t_token;

typedef struct s_elm
{
    char **cmd;
    int fd_in;
    int fd_out;
    struct s_elm *next;

}   t_elm;

typedef struct s_data
{
	int exit_asked;
    char *read_line;
    char **env;
   // char **command_list;
    t_token *tokens_list;
    t_elm   *exec_list;
}	t_data;

// minishell_loop
void    ft_minishell_loop(t_data *env);

// exit
void    ft_exit(t_data *data);

// TBD a suprimer a la fin
# include "minishell_julia.h"
# include "minishell_yann.h"

#endif