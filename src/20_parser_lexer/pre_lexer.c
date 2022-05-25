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
*******************************************************************/
void    ft_check_multiples_pipes(char *str)
{
    int i; 

    i = 0;
    while (str[i] == '\t' || str[i] == ' ') // voir si ca concerne tous les isspaces ou pas
        i++;
    if (str[i] == '|')
        ft_lexer_error("Error: syntax error near unexpected token `|'");
    while (str[i] != '|')
    {
        if (str[i] != ' ' || str[i] != '\t')
            i++;
        
    }
    ft_printf("Pipes ok\n");
}

/*******************************************************************
Return error if :
- 3 or more < > are stuck together 

Cas gérés comme des erreurs : 
- 
****************************************************************** 
*/