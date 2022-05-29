/* Define TOKENS */

typedef enum token
{
    PIPE,
    DOLLARS,
    REDIRECT_IN,
    REDIRECT_OUT,
    HEREDOC,
    D_REDIRECT_OUT,
    S_QUOTE,
    D_QUOTE,
    SPACE,
}   t_enum_token;

/* LEXER */
void    ft_minishell(t_data *input_minishell);
t_token *ft_lexer(char *read_line,t_token *tokenizer);
void    ft_parse_quote(t_data *input);
void    ft_search_quotes(char *str);
char    *ft_check_multiples_pipes(char *str);
char    **ft_get_word_into_quote(char quote_type, char *str);

/* ----------- ERRORS ------------*/
void    ft_lexer_error(char *msg);
void    ft_pre_check_input(void);

