#include "minishell.h"

/*----------------------------- LEXER ------------------------------

- Récupérer la string entree en input avec readline
- FIRST CHECK : if there are invalid nb of pipes, chevrons ou des chevrons mal orientés
- SECOND CHECK : if there are squotes || dquotes 

Si dquote ou squote :
    -> Si squote ou dquote non fermées : erreur
    -> Parser et checker si on trouve des pipes au milieu de squotes || dquotes
        -> Si dquote :
            -> tout ce qui est entre dquote == token 
        -> Si squote : tout ce qui est entre squotes == token 
    -> Parser et chequer si on trouve des < >  << >> au milieu des squotes || dquotes
        -> Si dquote || squote :
                -> le resultat == token + dquotes
                -> le resultat == token
Si absence de squote ou dquote :
    -> Parser et découper l'input en fonction des pipes.

Si il n'y a pas de pipes


TOKEN == mots qui seront interprétés plus tard.
TOCKENS stockés dans un char** (ft_get_tokens).

-----------------------------------------------------------------------*/


/*-------------------------------------------------
Return 0 in there are no | or no << >> in quotes 
return 1 if there are | or <> << >> in quotes 
--------------------------------------------------*/ 
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



/* Check if there are quotes int the string*/
void ft_search_quotes(char *str)
{
    if (ft_strchr(str, '"') || ft_strchr(str, '\''))
    {
        // lauch pre-parsing
        //ft_printf("String contains dquote or squote");
        ft_is_operator_into_quotes(str);
        ft_check_multiples_pipes(str);
        exit(EXIT_SUCCESS);
    }
    else
    {
        // lauch parsing classic
        ft_check_multiples_pipes(str);
        ft_printf("String no contains quote");
    }
    exit(EXIT_FAILURE);
}

/*** 
If ft_search_quotes return : NO QUOTES 

***/
//int ft_check_pipes_in_quotes(char *str)
/*

*/

//int ft_is_str_get_pipes(char *str)
/* 
--> return 0 if no pipe are found in the string 
--> return 1 if 1 or more pipe are found in the string.
*/

//void    ft_trunck_isspaces(char *str)
/* str_trim ? 
- remove start and end isspace from the string
*/

//char**    ft_get_tokens(char *str)
/* == str_tokens 
  if ft_search_quote return (1 == no quotes)
    if ft_is_pipe return 1
    -->
- else (if ft_is_pipe return 0)
    --> str[0] == str && str[1] == NULL 

}
*/