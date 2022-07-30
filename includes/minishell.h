/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:14:58 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:15:00 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <signal.h>
# include <string.h>

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;

}	t_token;

typedef struct s_fd_heredoc
{
	int					fd;
	struct s_fd_heredoc	*next;

}	t_fd_heredoc;

typedef struct s_exec_elm
{
	char				**cmd;
	int					fd_in;
	int					fd_out;
	int					index;
	int					has_redirect_pb;
	pid_t				pid;
	struct s_exec_elm	*next;

}	t_exec_elm;

typedef struct s_data
{
	int				exit_asked;
	char			*read_line;
	char			**env;
	int				last_pipeline_exit_status;
	int				nb_of_process;
	t_token			*tokens_list;
	t_token			*gp_tokens_list;
	t_exec_elm		*exec_list;
	t_fd_heredoc	*fd_lst;
	int				fd_save_stdout;
	int				fd_save_stdin;
	t_list			*garbage_collector;
}	t_data;

// minishell_loop
void			ft_minishell_loop(t_data *env);

//-----------------------------------------
//           10_initialisation
//-----------------------------------------
// 10_initialisation
// data initialisation
void			ft_initialisation(t_data *data, char **envp);
void			ft_reinitialisation_read_data(t_data *data);

//-----------------------------------------
//           15_minishel_loop
//-----------------------------------------
// minishell_loop
int				ft_get_cmd(t_data *data);
void			ft_minishell_loop(t_data *data);

//-----------------------------------------
//           17_error_management
//-----------------------------------------
// error_cd.c
int				ft_cd_error_too_many_arg(t_data *data);
int				ft_cd_error_no_arg(t_data *data);
int				ft_cd_error_no_dir(t_data *data, char *cmd);
// error_close.c
void			ft_exit_close_error(t_data *data);
// error_cmd_not_found.c
void			ft_exit_cmd_not_found_error(t_data *data, char **cmd);
// error_dup2.c
void			ft_exit_dup_error(t_data *data);
// error_execve.c
void			ft_exit_execve_error(t_data *data);
// error_exit
int				ft_print_exit_error_too_many_arg(t_data *data);
int				ft_exit_print_error_not_numeric_arg(t_data *data, char *arg);
// error_fork.c
void			ft_exit_fork_error(t_data *data);
// error_pipe.c
void			ft_exit_pipe_error(t_data *data);
// error_pwd
int				ft_pwd_error(t_data *data);
// print_error.c
void			ft_print_error(t_data *data, int error_status);
// print_error_open.c
void			ft_print_open_error(t_data *data, char *file_name);

/*----------------------------------------
  20_LEXER
  -----------------------------------------*/
/******** lexer.c ************/
void			ft_minishell(t_data *data);
void			ft_fill_new_token(char *content, t_data *data, int type);
int				ft_lexer(t_data *data);

/******** lexer_metacharacters.c ************/
int				ft_get_separators(t_data *data, int index);
int				ft_is_space_sep(char c);

/******** lexer_words.c ************/
int				ft_get_word(t_data *data, int index);
int				ft_fill_tokens_list(t_data *data);

/******** lexer_utils.c ************/
int				ft_check_unclose_quote(char	*line);
int				ft_is_word(char *line, int index);

/*----------------------------------------
  21_PARSER
  -----------------------------------------*/

/******** parser.c ************/
int				ft_parser(t_data *data);
int				ft_pipe_errors(t_token *token);

/******** parser_utils.c ************/
int				ft_pre_parser(t_data *data, t_token *list);
int				ft_is_redirect_err(t_token *token);
int				ft_is_empty_list(t_token *list);
int				ft_is_empty_pipe(t_token *token);
int				ft_is_next_tkn_ok(int type);
int				ft_is_only_spc(char *str);

//-----------------------------------------
//               22 heredoc
//-----------------------------------------
/******** heredoc.c ************/
int				ft_heredoc(t_data *data, t_token *heredoc_tkn);

/******** heredoc_utils.c ************/
int				ft_is_quoted(char *heretag);
void			ft_wait_pid_heredoc(int id, t_data *data);
int				ft_is_expand_required(char *heretag);

/******** heredoc_manipulation.c ************/
t_fd_heredoc	*ft_new_fd(t_data *data, int fd);
void			ft_lstadd_back_fd(t_fd_heredoc **alst, t_fd_heredoc *new);
void			ft_print_fds_list(t_fd_heredoc *fd_list);
t_fd_heredoc	*ft_lstlast_fd(t_fd_heredoc*lst);
t_fd_heredoc	*ft_pop_first_fd_lst(t_data *data);

/*----------------------------------------
  23_LIST TOKENS
  -----------------------------------------*/
void			ft_group_tokens(t_data *data);
t_token			*ft_fill_redir_tkn(t_data *data, t_token *list);
int				ft_get_redir_tkn(t_data *data, char *content, int type);
void			ft_fill_new_token_2(char *content, t_data *data, int type);

/*----------------------------------------
  24_SIGNALS
  -----------------------------------------*/
/********** signals_1.c ****************/
void			ft_handle_exec_sigint(int signal);
void			ft_handle_exec_signal(void);
void			ft_handle_exec_sigquit(int signal);

/********** signals_2.c ****************/
void			ft_handle_signals(void);
void			ft_handle_sigint(int signal);
void			ft_handle_sigquit(int signal);
void			ft_handle_ctrld(t_data *data);
void			ft_init_ptr(t_data *data);

/********** signals_3.c ****************/
void			ft_handle_heredoc_signal(void);
void			ft_sigint_heredoc(int signal);
void			ft_handle_ctrld_heredoc(t_data *data, char *end);

//-----------------------------------------
//               25 expand
//-----------------------------------------
// expand.c
void			ft_expand_token(t_data *data, t_token *token);
void			ft_expand(t_data *data);
void			ft_expand_str(t_data *data, char **str);
int				ft_is_next_word_to_expand(t_token *token);
void			ft_expand_normal_key(t_data *data, char **str, int *i);
void			ft_expand_pipeline_exit_status(t_data *data, char **str,
					int *i);
char			*ft_get_key_for_expand(t_data *data, char *str);
int				ft_key_size_for_expand(t_data *data, char *str);
//----------------------------------------
//              27_rm_quotes
//-----------------------------------------
void			ft_rm_quotes_in_tokens_list(t_data *data);
void			ft_rm_quotes_in_token(t_data *data, t_token *token);
void			ft_rm_quotes_in_str(t_data *data, char **str);
int				manage_close_s_quote(t_data *data, char **str, int *i);
int				manage_close_d_quote(t_data *data, char **str, int *i);
int				manage_open_s_quote(t_data *data, char **str, int *i);
int				manage_open_d_quote(t_data *data, char **str, int *i);

//-----------------------------------------
//          28_exec_list_creation
//-----------------------------------------
// count_pipes
int				ft_count_pipe(t_data *data, t_token *token_list);
// create_exec_elm_list
void			ft_create_exec_elm_list(t_data *data);

//-----------------------------------------
//    30_read_gp_token_to_fill_exec_list
//-----------------------------------------

// read_gp_token_list.c
void			ft_build_exec_list(t_data *data);
// read_redirection_token.c
int				ft_set_exec_t_redirect_in(t_data *data, t_token *token,
					int process);
int				ft_set_exec_t_redirect_out(t_data *data, t_token *token,
					int process);
int				ft_set_exec_d_redirect_out(t_data *data, t_token *token,
					int process);
int				ft_set_exec_t_redirect_token(t_data *data, t_token *token,
					int process);
// read_token_cmd.c
void			ft_set_exec_with_t_cmd_token(t_data *data, t_token *token,
					int process);
void			ft_add_to_command_list(t_data *data, char ***cmd_lst,
					char *to_add);
// read_token_heredoc
void			ft_set_exec_with_t_heredoc(t_data *data, t_token *token,
					int process);

//-----------------------------------------
//          36_command_execution
//-----------------------------------------
//close_fd.c
void			ft_close_fd_exept_current(t_data *data, int current_index);
//exec_all_commands.c
void			ft_exec_all_cmds(t_data *data);
//exec_one_command.c
void			ft_exec_builtin(t_data *data, char **cmd);
void			ft_exec_one_command(t_data *data, t_exec_elm *exec_elm);
//find_command_path.c
char			*ft_find_command(t_data *data, char *cmd, char **envp);
// manage_fd_and_redirections.c
void			ft_save_stdin_out(t_data *data);
void			ft_restore_stdin_out(t_data *data);
void			ft_make_fd_redirection(t_data *data, t_exec_elm *exec_elm);

//-----------------------------------------
//               40 builtin
//-----------------------------------------
int				ft_builtin_echo(t_data *data, char **cmd);
int				ft_builtin_env(t_data *data, char **cmd);
int				ft_builtin_cd(t_data *data, char **cmd);
int				ft_builtin_exit(t_data *data, char **cmd);
int				ft_builtin_pwd(t_data *data, char **cmd);
int				ft_is_builtin(t_data *data, char **cmd);
int				ft_builtin_unset(t_data *data, char **cmd);
int				ft_is_valid_identifier(char *cmd);
void			ft_rm_str_from_env(t_data *data, char **new_env, char *var,
					int len);
int				ft_builtin_export(t_data *data, char **cmd);
void			ft_print_env(char **env);

//-----------------------------------------
//             45_environment
//-----------------------------------------
// env_initialisation
void			ft_dup_env(t_data *data, char **envp);
// env_manipulation_1.c
int				ft_env_nb_of_lines(char **envp);
char			*ft_env_get_key_on_line(t_data *data, char *line);
char			*ft_env_get_value_on_line(t_data *data, char *line);
int				ft_max_len(char *str1, char *str2);
int				ft_env_key_is_present(t_data *data, char *key_searched);
// env_manipulation_2.c
char			*ft_env_get_value(t_data *data, char *key_searched);

//-----------------------------------------
//           50_exit functions
//-----------------------------------------
// exit
void			ft_exit(t_data *data);
void			ft_exit2(t_data *data, int error_status);

//-----------------------------------------
//           60_tools
//-----------------------------------------
// exec_elm_manipulation.c
t_exec_elm		*ft_create_new_exec_elm(t_data *data);
void			ft_add_exec_elm(t_exec_elm **elm_list, t_exec_elm *new_elm);
t_exec_elm		*ft_create_empty_exec_elm_list(t_data *data, int nb_elm);
t_exec_elm		*ft_get_last_exec_elm(t_exec_elm *lst);
t_exec_elm		*ft_get_exec_elm(t_exec_elm *lst, int index);
// ft_add_to_str.c
void			ft_add_to_str(t_data *data, char **str, char *to_add,
					int position);
void			ft_add_to_str_end(t_data *data, char **str, char *to_add);
//ft_null_terminated_tab_len.c
size_t			ft_null_terminated_tab_len(char **tab);
// ft_rm_from_str.c
void			ft_rm_from_str(t_data *data, char **s, int rm_len,
					int position);
// ft_split with garbage collector
char			**ft_split_garbage_collector(t_data *data, char const *s,
					char c);
void			ft_free_split_garbage_collector(t_data *data, char **split_str);
// lst_manipulation.c
void			ft_lst_add(t_exec_elm **elm_list, t_exec_elm *new_elm);
t_exec_elm		*ft_lst_get_last_elm(t_exec_elm *lst);
// garbage collector 1
void			ft_init_garbage_collector(t_data *data);
void			*ft_malloc(t_data *data, size_t size);
void			ft_add_to_garbage_collector(t_data *data, void *content);
void			ft_free_garbage_collector(t_data *data);
// garbage collector 2
void			ft_print_garbage_collector(t_data *data);
void			ft_free(t_data *data, void *address);
// print_color
void			ft_print_color(char *str);
/******** tkn_manipulation.c ************/
void			ft_lstadd_back_token(t_token **alst, t_token *new);
t_token			*ft_new_token(t_data *data, char *value, int type);
t_token			*ft_lstlast_token(t_token *lst);
/******** ft_strcmp.c ************/
int				ft_strcmp(char *s1, char *s2);

#endif
