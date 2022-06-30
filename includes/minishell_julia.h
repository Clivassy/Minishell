#include <errno.h>
#include <string.h>

# define    ERROR -1
# define    ERROR_EMPTY_LST -2
/*----------------------------------------
                LEXER
-----------------------------------------*/

/******** lexer.c ************/
void    ft_minishell(t_data *data);
t_token *ft_lexer(t_data *data);

/******** lexer_metacharacters.c ************/
int     ft_get_separators(t_data *data, int index);
int	ft_is_space_sep(char c);

/******** lexer_words.c ************/
int     ft_get_word(t_data *data, int index);
void    ft_fill_new_token(char *content, t_data *data, int type);

/******** lexer_utils.c ************/
int     ft_check_unclose_quote(char	*line);
int     ft_is_word(char *line, int index);

/*----------------------------------------
                PARSER
-----------------------------------------*/

/******** parser.c ************/
int ft_parser(t_data *data);
int ft_pipe_errors(t_token *token);

/******** heredoc.c ************/

int ft_heredoc(t_data *data, t_token *heredoc_tkn);
int	ft_strcmp(char *s1, char *s2);
char *ft_read_heredoc(t_data *data, char *str, char *heretag);
void ft_test(int file[2]);

/* ----------- ERRORS ------------*/
void    ft_lexer_error(char *msg);
void ft_is_empty_list(t_token *list);
/*----------------------------------------
            LIST TOKENS
-----------------------------------------*/

int ft_group_tokens(t_data *data);
// 60_tools //
/******** tkn_manipulation.c ************/
void    ft_lstadd_back_token(t_token **alst, t_token *new);
t_token *ft_new_token(char *value, int type);
t_token *ft_lstlast_token(t_token *lst);
