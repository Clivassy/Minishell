// TBD copier contenu minishell_yann.h dans minishell.h

//commandes pour tests
// clear && make yann && ./minishell


// Initialisation
void    dup_env(t_data *data, char **envp);

// exec_command
void    ft_exec_command(t_data *data);
void    ft_launch_processus(t_data *data, int index);

// 40 builtin
void    ft_echo(char **argument_list);
void	ft_cd(char **arguments);

// 60_tools
// env_manipulation
int nb_of_env_lines(char **envp);
// elm_manipulation.c
t_elm	*ft_elm_ceate_new(t_data *data, char **cmd, int fd_in, int fd_out);
// lst_manipulation.c
void    ft_lst_print(t_elm *elm);
void    ft_lst_add(t_elm **elm_list, t_elm *new_elm);
t_elm	*ft_lst_get_last_elm(t_elm *lst);

// 70 debug
void    print_env(char **env);
void    ft_test_echo();

