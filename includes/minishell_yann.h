// TBD copier contenu minishell_yann.h dans minishell.h

//commandes pour tests
// clear && make yann && ./minishell

// 10_initialisation
// data initialisation
void	ft_data_initialisation(t_data *data);

// exec_command
void    ft_exec_command(t_data *data);
void    ft_launch_processus(t_data *data, int index);

// 40 builtin
void    ft_echo(char **argument_list);
void	ft_cd(char **arguments);

// 45_environment
// env_initialisation
void	dup_env(t_data *data, char **envp);
// env_manipulation
int nb_of_env_lines(char **envp);


// 60_tools

// elm_manipulation.c
t_elm	*ft_elm_ceate_new(t_data *data, char **cmd, int fd_in, int fd_out);
// lst_manipulation.c
void    ft_lst_print(t_elm *elm);
void    ft_lst_add(t_elm **elm_list, t_elm *new_elm);
t_elm	*ft_lst_get_last_elm(t_elm *lst);
// garbage collector
void	ft_init_garbage_collector(t_data *data);
void	*ft_malloc(t_data *data, size_t size);
void	ft_add_to_garbage_collector(t_data *data, void *content);
void	ft_free_garbage_collector(t_data *data);
void	ft_print_garbage_collector(t_data *data);
void	ft_free(t_data *data, void *address);
// print_color
void	ft_print_color(char *str);


// 70 debug
void    print_env(char **env);
void    ft_test_echo();
void    ft_test_garbage_collector(t_data *data);


