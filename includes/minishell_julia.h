#include <errno.h>
#include <string.h>

/* LEXER */
void    ft_minishell(t_data *input_minishell);
t_token *ft_lexer(char *readline);
void    ft_parse_quote(t_data *input);
void    ft_search_quotes(char *str);
char    *ft_check_multiples_pipes(char *str);
char    **ft_get_word_into_quote(char quote_type, char *str);

/* ----------- ERRORS ------------*/
void    ft_lexer_error(char *msg);
void    ft_pre_check_input(void);

/* LIST TOKENS*/
void	ft_lstadd_back_token(t_token **alst, t_token *new);
t_token	*ft_new_token(char *value, int type);
t_token	*ft_lstlast_token(t_token *lst);
void    ft_print_token_list(t_token *elm);

