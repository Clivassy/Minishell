#include "minishell.h"

/*----------------------------- LEXER ------------------------------

1 ) Récupérer la string entrée en input avec readline.
2 ) Séparer la string en fonction des metacharaters : espaces, $, "", '', | 
3 ) Parsing : analyse des morceaux de phrase : simple command, pipeline , redirections
== Tokenisation : CMD // PIPE // Chevron in/ out // heredoc // >>
-----------------------------------------------------------------------*/

/*-------------------------------------------------
Return 0 in there are no | or no << >> in quotes 
return 1 if there are | or <> << >> in quotes 
--------------------------------------------------*/ 
/*int ft_is_operator_into_quotes(char *str)
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


 Check if there are quotes int the string
void ft_search_quotes(char *str)
{
        exit(EXIT_SUCCESS);
    }
    else
    {
        ft_check_multiples_pipes(str);
        ft_printf("String no contains quote");
    }
    exit(EXIT_FAILURE);
}

*/