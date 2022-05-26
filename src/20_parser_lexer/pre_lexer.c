#include "minishell.h"

/*******************************************************************
Return error if : 
Standard input is NOT from the terminal 
*******************************************************************/

void    ft_pre_check_input(void)
{
    if (!isatty(0)) // check if the standar input is from a terminal
        ft_lexer_error("Error: standard input in not from a terminal");
}

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

/*******************************************************************
Return error if :
- 3 or more < > are stuck together 

Cas gérés comme des erreurs : 
- 
****************************************************************** 
*/