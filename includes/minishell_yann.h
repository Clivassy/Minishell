// TBD copier contenu minishell_yann.h dans minishell.h

//commandes pour tests
// clear && make yann && ./minishell

// 10_initialisation
// data initialisation
void	ft_data_initialisation(t_data *data);

//25 expand
// expand.c
char	*ft_get_word_for_expand(t_data *data, char *str);
int	ft_word_size(t_data *data, char *str);
int	ft_word_size_after_expand(t_data *data, char *word);
int	ft_size_after_expand(t_data *data, char *str);

// exec_command
void    ft_exec_command(t_data *data);
void    ft_launch_processus(t_data *data, int index);

// 40 builtin
void    ft_echo(char **argument_list);
void	ft_cd(char **arguments);

// 45_environment
// env_initialisation
void	ft_dup_env(t_data *data, char **envp);
// env_manipulation
int ft_env_nb_of_lines(char **envp);
char *ft_env_get_key_on_line(t_data *data, char *line);
char *ft_env_get_value_on_line(t_data *data, char *line);
int ft_max_len(char *str1, char *str2);
int	ft_env_key_is_present(t_data *data, char *key_searched);
char *ft_env_get_value(t_data *data, char *key_searched);

// 60_tools
// ft_add_to_string.c
void	ft_add_to_str(t_data *data, char **str, char *to_add, int position);
// elm_manipulation.c
t_elm	*ft_elm_ceate_new(t_data *data, char **cmd, int fd_in, int fd_out);
// lst_manipulation.c
void    ft_lst_print(t_elm *elm);
void    ft_lst_add(t_elm **elm_list, t_elm *new_elm);
t_elm	*ft_lst_get_last_elm(t_elm *lst);

// print_color
void	ft_print_color(char *str);


// 70 debug
void    print_env(char **env);
void	ft_test_add_to_str(t_data *data);
void    ft_test_echo();
void    ft_test_garbage_collector(t_data *data);
void	ft_test_env(t_data *data);
void	ft_expand(t_data *data);



