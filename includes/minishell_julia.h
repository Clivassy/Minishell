#include <signal.h> 
#include <string.h> 
/*----------------------------------------
               20_LEXER
-----------------------------------------*/

/******** lexer.c ************/
void    ft_minishell(t_data *data);
void    ft_fill_new_token(char *content, t_data *data, int type);
int    ft_lexer(t_data *data);

/******** lexer_metacharacters.c ************/
int     ft_get_separators(t_data *data, int index);
int	ft_is_space_sep(char c);

/******** lexer_words.c ************/
int     ft_get_word(t_data *data, int index);
int    ft_fill_tokens_list(t_data *data);

/******** lexer_utils.c ************/
int     ft_check_unclose_quote(char	*line);
int     ft_is_word(char *line, int index);

/*----------------------------------------
                21_PARSER
-----------------------------------------*/

/******** parser.c ************/
int ft_parser(t_data *data);
int ft_pipe_errors(t_token *token);

/******** parser_utils.c ************/
int ft_pre_parser(t_data *data, t_token *list);
int ft_is_redirect_err(t_token *token);
int ft_is_empty_list(t_token *list);
int ft_is_empty_pipe(t_token *token);
int ft_is_next_tkn_ok(int type);
int ft_is_only_spc(char *str);
/*----------------------------------------
                22_HEREDOC
-----------------------------------------*/
/******** heredoc.c ************/
int ft_heredoc(t_data *data, t_token *heredoc_tkn);

/******** heredoc_utils.c ************/
int         ft_is_quoted(char *heretag);

int         ft_is_expand_required(char *heretag);

/******** heredoc_manipulation.c ************/
t_fd_heredoc    *ft_new_fd(t_data *data, int fd);
void            ft_lstadd_back_fd(t_fd_heredoc **alst, t_fd_heredoc *new);
void            ft_print_fds_list(t_fd_heredoc *fd_list);
t_fd_heredoc	*ft_lstlast_fd(t_fd_heredoc*lst);

/*----------------------------------------
            23_LIST TOKENS
-----------------------------------------*/
void    ft_group_tokens(t_data *data);
t_token *ft_fill_redir_tkn(t_data *data, t_token *list);
int     ft_get_redir_tkn(t_data *data, char *content, int type);
void    ft_fill_new_token_2(char *content, t_data *data, int type);

/*----------------------------------------
            24_SIGNALS
-----------------------------------------*/
/********** signals.c ****************/
void    ft_handle_ctrld(t_data *data);
void    ft_handle_signals(void);
void    ft_handle_sigint(int signal);
void    ft_handle_sigquit(int signal);
void    ft_handle_heredoc_signal(void);
void    ft_sigint_heredoc(int signal);
void    ft_handle_ctrld_heredoc(t_data *data, char *end);

/*----------------------------------------
            40_BUILTINS
-----------------------------------------*/
/********** builtins_unset.c ****************/
void    ft_test_unset(t_data *data, char **envp, char **argv);
int     ft_builtin_unset(t_data *data, char **cmd);
int     ft_is_valid_identifier(char *cmd);
void    ft_rm_str_from_env(t_data *data, char **new_env, char *var, int len);

/********** builtins_export.c ****************/
void    ft_test_export(t_data *data, char **envp, char **argv);
int ft_builtin_export(t_data *data, char **cmd);
/*----------------------------------------
            60_TOOLS
-----------------------------------------*/
/******** tkn_manipulation.c ************/
void    ft_lstadd_back_token(t_token **alst, t_token *new);
t_token	*ft_new_token(t_data *data, char *value, int type);
t_token *ft_lstlast_token(t_token *lst);

/******** ft_strcmp.c ************/
int	        ft_strcmp(char *s1, char *s2);

/********** TEMP ****************/
int ft_is_empty_list(t_token *list);

/* TEST */
void ft_test(int file[2]);
void    ft_debeug(t_data *data, char *msg, char **env, char *color);

