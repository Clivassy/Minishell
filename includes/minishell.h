#ifndef MINISHELL_H
# define MINISHELL_H

/* Define TOKENS */
# define    T_PIPE 1
# define    T_REDIRECT_IN 2
# define    T_REDIRECT_OUT 3
# define    T_HEREDOC 4
# define    D_REDIRECT_OUT 5
# define    S_QUOTE 6
# define    D_QUOTE 7
# define    T_SPACE 8
# define    T_WORD 9
# define    T_CMD 10

//Colors
# define COLOR_NORMAL  "\x1B[0m"
# define COLOR_RED  "\x1B[31m"
# define COLOR_GREEN  "\x1B[32m"
# define COLOR_YELLOW  "\x1B[33m"
# define COLOR_BLUE  "\x1B[34m"
# define COLOR_MAGENTA  "\x1B[35m"
# define COLOR_CYAN  "\x1B[36m"
# define COLOR_WHITE  "\x1B[37m"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "error_message.h"

typedef struct s_token
{
    int type;
    char *value;
    struct s_token *next;

}   t_token;

typedef struct s_exec_elm
{
    char **cmd;
    int fd_in;
    int fd_out;
	int index;
	pid_t pid;
    struct s_exec_elm *next;

}   t_exec_elm;

typedef struct s_data
{
	int		exit_asked;
    char	*read_line;
    char	**env;
	int		last_pipeline_exit_status;
	int		nb_of_process;
   // char **command_list;
    t_token	*tokens_list;
    t_token *gp_tokens_list;
    t_exec_elm	*exec_list;
	t_list	*garbage_collector;
}	t_data;

// minishell_loop
void    ft_minishell_loop(t_data *env);

// exit
void    ft_exit(t_data *data);

//-----------------------------------------
//           60_tools
//-----------------------------------------
// garbage collector 1
void	ft_init_garbage_collector(t_data *data);
void	*ft_malloc(t_data *data, size_t size);
void	ft_add_to_garbage_collector(t_data *data, void *content);
void	ft_free_garbage_collector(t_data *data);
void	ft_print_garbage_collector(t_data *data);
// garbage collector 2
void	ft_free(t_data *data, void *address);

// TBD a suprimer a la fin
# include "minishell_julia.h"
# include "minishell_yann.h"

#endif
