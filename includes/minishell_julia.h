#include <errno.h>
#include <string.h>

/* LEXER */
int ft_check_non_close_quotes(char *line, int i, char quote_type);
int     ft_is_double_redirect(char *str, int index, char c);
int     ft_get_mixed_token(t_data *data, char *read_line, int index, int len);
int     ft_get_separators(t_data *data, int index);
t_token *ft_lexer(t_data *data);
void    ft_fill_new_token(char *content, t_data *data, int type);
int     ft_check_no_space(char *line, int index, char c);
void    ft_minishell(t_data *data);
int     ft_is_word(char *line, int index);
int     ft_word_len(char *read_line, int index);
void    ft_parse_quote(t_data *input);
void    ft_search_quotes(char *str);
char    *ft_check_multiples_pipes(char *str);
int     ft_get_word(t_data *data, int index);
int     ft_get_quotes_token(t_data *data, char *read_line, int index);
char    **ft_get_word_into_quote(char quote_type, char *str);
int     ft_quote_word_len(char *read_line, int index);
int     ft_word_into_quotes(t_data *data, char *read_line, int index, int len);
int     ft_is_redirect(t_data *data, char *read_line, int index);
int     ft_is_space(t_data *data, char *read_line, int index);


/* PARSER */

int ft_parser(t_data *data);
int ft_pipe_errors(t_token *token);

/* ----------- ERRORS ------------*/
void    ft_lexer_error(char *msg);
void    ft_pre_check_input(void);

/* LIST TOKENS*/
void    ft_lstadd_back_token(t_token **alst, t_token *new);
t_token *ft_new_token(char *value, int type);
t_token *ft_lstlast_token(t_token *lst);
void    ft_print_token_list(t_token *elm);

