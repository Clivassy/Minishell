#include "minishell.h"

/*----------------------------- LEXER ------------------------------*/

/*******************************************************************/

/*- Récuperer la string entree en input avec readline
- FIRST CHECK : if there are squotes || dquotes 

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
TOCKENS stockés dans un char** (ft_get_tokens).*/

/********************************************************************/

char**    ft_get_tokens(char *str)
{
    // get ride of isspace at the beggining && and the end of the string 
    // -> str_trim ? 
    // Handle multiple pipes
    return (NULL);
}