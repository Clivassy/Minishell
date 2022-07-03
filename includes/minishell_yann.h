// TBD copier contenu minishell_yann.h dans minishell.h

//-----------------------------------------
//           10_initialisation
//-----------------------------------------
// 10_initialisation
// data initialisation
void	ft_initialisation(t_data *data, char **envp);
void	ft_reinitialisation_read_data(t_data *data);

//-----------------------------------------
//           15_minishel_loop
//-----------------------------------------
// minishell_loop
int	ft_get_cmd(t_data *data);
void	ft_minishell_loop(t_data *data);

//-----------------------------------------
//           17_error_management
//-----------------------------------------
void	ft_print_error(t_data *data, int error_status);

//-----------------------------------------
//               25 expand
//-----------------------------------------
// expand.c
void	ft_expand_token(t_data *data, t_token *token);
void	ft_expand(t_data *data);
void	ft_expand_str(t_data *data, char **str);

//----------------------------------------
//              27_rm_quotes
//-----------------------------------------
void	ft_rm_quotes_in_tokens_list(t_data *data);
void	ft_rm_quotes_in_token(t_data *data, t_token *token);
void	ft_rm_quotes_in_str(t_data *data, char **str);


//-----------------------------------------
//          28_exec_list_creation
//-----------------------------------------
// count_pipes
int	ft_count_pipe(t_data *data, t_token *token_list);
// create_exec_elm_list
void	ft_create_exec_elm_list(t_data *data);

//-----------------------------------------
//    30_read_gp_token_to_fill_exec_list
//-----------------------------------------

// read_gp_token_list.c
void	ft_build_exec_list(t_data *data);
// read_redirection_token.c
void	ft_set_exec_t_redirect_in(t_data *data, t_token *token, int process);
void	ft_set_exec_t_redirect_out(t_data *data, t_token *token, int process);
void	ft_set_exec_d_redirect_out(t_data *data, t_token *token, int process);
// read_token_cmd.c
void	ft_set_exec_with_t_cmd_token(t_data *data, t_token *token, int process);
void	ft_add_to_command_list(t_data *data, char ***cmd_lst, char *to_add);
// read_token_heredoc
void	ft_set_exec_with_t_heredoc(t_data *data, t_token *token, int process);

//-----------------------------------------
//          36_command_execution
//-----------------------------------------
//exec_command.c
void    ft_launch_processus(t_data *data, t_exec_elm *exec_elm);
void    ft_exec_cmd(t_data *data);
// find_command_path.c
void	ft_launch_command(char **cmd, char **envp);
char	*ft_find_command(char *cmd, char **envp);
char	*ft_check_path_command(char **paths, char *cmd);

//-----------------------------------------
//               40 builtin
//-----------------------------------------
void    ft_echo(char **argument_list);
void	ft_cd(char **arguments);

//-----------------------------------------
//             45_environment
//-----------------------------------------
// env_initialisation
void	ft_dup_env(t_data *data, char **envp);
// env_manipulation
int ft_env_nb_of_lines(char **envp);
char *ft_env_get_key_on_line(t_data *data, char *line);
char *ft_env_get_value_on_line(t_data *data, char *line);
int ft_max_len(char *str1, char *str2);
int	ft_env_key_is_present(t_data *data, char *key_searched);
char *ft_env_get_value(t_data *data, char *key_searched);

//-----------------------------------------
//                60_tools
//-----------------------------------------
// create_exec_list.c
void	create_exec_list_1(t_data *data);
// create token list
void	create_token_list_1(t_data *data);
void	create_token_list_2(t_data *data);
void	create_token_list_3(t_data *data);
void	create_token_list_empty(t_data *data);
void	create_token_list_1_elm(t_data *data);
void	create_token_list_3elm_avec_pipe(t_data *data);
void	create_gp_token_list_1(t_data *data);
// exec_elm_manipulation.c
t_exec_elm	*ft_create_new_exec_elm(t_data *data);
void    ft_add_exec_elm(t_exec_elm **elm_list, t_exec_elm *new_elm);
t_exec_elm	*ft_create_empty_exec_elm_list(t_data *data, int nb_elm);
t_exec_elm	*ft_get_last_exec_elm(t_exec_elm *lst);
t_exec_elm	*ft_get_exec_elm(t_exec_elm *lst, int index);
// ft_add_to_str.c
void	ft_add_to_str(t_data *data, char **str, char *to_add, int position);
void	ft_add_to_str_end(t_data *data, char **str, char *to_add);
// ft_rm_from_str.c
void	ft_rm_from_str(t_data *data, char **s, int rm_len, int position);
// lst_manipulation.c
void    ft_lst_add(t_exec_elm **elm_list, t_exec_elm *new_elm);
t_exec_elm	*ft_lst_get_last_elm(t_exec_elm *lst);

// print_color
void	ft_print_color(char *str);

//-----------------------------------------
//               70 debug
//-----------------------------------------
void    ft_print_env(char **env);
void    ft_exec_elm_lst_print(t_exec_elm *elm);
void    ft_print_token_list(t_token *token_list);
void	ft_test_add_to_str(t_data *data);
void	ft_test_add_to_str_end(t_data *data);
void	ft_test_rm_from_str(t_data *data);
void	ft_test_command_execution(t_data *data);
void    ft_test_echo();
void	ft_test_env(t_data *data);
void	ft_test_exec_list_creation(t_data *data);
void	ft_test_expand_str(t_data *data);
void	ft_test_expand_token(t_data *data);
void	ft_test_expand(t_data *data);
void    ft_test_garbage_collector(t_data *data);
void	ft_test_rm_quotes_in_str(t_data *data);
void	ft_test_rm_quotes_in_token(t_data *data);
void	ft_test_rm_quotes_in_token_list(t_data *data);
void	ft_test_ft_set_exec_t_redirect_in(t_data *data);




