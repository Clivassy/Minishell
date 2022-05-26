typedef struct s_token
{
    char *token;
    struct s_token *next;

}   t_token;

/* LEXER */
void    ft_parse_quote(t_data *input);
void    ft_search_quotes(char *str);
char    *ft_check_multiples_pipes(char *str);
char    **ft_get_word_into_quote(char quote_type, char *str);

/* ----------- ERRORS ------------*/
void    ft_lexer_error(char *msg);
void    ft_pre_check_input(void);