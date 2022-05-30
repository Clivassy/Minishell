#include "minishell.h"

/*******************************************************************
Return error if :
- 2 of more pipe are stuck together 

Cas gérés comme des erreurs : 
- Pipe en début d'input
- Double pipe ou +
- Pipe - isspace - pipe 
- Succession de pipe et chevrons au tout debut de l'input 

*******************************************************************/
char    *ft_check_multiples_pipes(char *str)
{
    int i; 

    i = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '>'
			|| str[i] == '<' || str[i] == '|'))
    {
        if (str[i] == '|')
            ft_lexer_error("Error: succesion d'operateur en debut d'input");
        i++;
    }
    while (str[i])
    {
        if (str[i] && str[i] == '|')
        {
            i++;
            while (str[i] && (str[i] == ' ' || str[i] == '>'
			|| str[i] == '<' || str[i] == '|'))
            {
                if (str[i] == '|')
                    ft_lexer_error("Error: uniquement operateurs ou espaces au milieu de pipe");
                i++;
            }
        }
        i++;
    }
    ft_printf("Correct input format\n");
    return(str);
}
/************************************************
Return 0 in there are no | or no << >> in quotes 
return 1 if there are | or <> << >> in quotes 

**************************************************/ 
int ft_is_operator_into_quotes(char *str)
{
    int i;
    char quote_type;

    i = 0;
    while (str[i] && (str[i] != '"' && str[i] != '\''))
        i++;
    quote_type = str[i];
    //printf("\n%c", quote_type);
    i++;
    while (str[i])
    {   
        if (str[i] == quote_type)
            break;
        if (str[i] == '|' || str[i] == '<' || str[i] == '>')
        {
            ft_printf("found operator into dquotes");
            return (1);
        }
        i++;
    }
    ft_printf("found NO pipe into dquotes");
    return (0);
}