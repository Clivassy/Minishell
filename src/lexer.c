#include "minishell.h"

/*----------------------------- LEXER ------------------------------*/

/*******************************************************************/
/* 
- Récuperer la string entree en input avec readline
- FIRST CHECK : if there are squotes || dquotes 

////////////////////////////////////////////////////////////

Si dquote ou squote :
    -> Si squote ou dquote non fermées : voir ce qu' on fait (ammon)
    -> Parser et checker si on trouve des pipes au milieu de squotes || dquotes
        -> Si dquote :
            -> tout ce qui est entre dquote == token (a voir si $ check mtn ou + tard)
        -> Si squote : tout ce qui est entre squotes == token 
    -> Parser et chequer si on trouve des <><<>> au milieu des squotes || dquotes
        -> Si dquote || squote :
                -> le resultat == token + dquotes
                -> le resultat == token
Si absence de squote ou dquote :
    -> Parser et découper l'input en fonction des pipes.

//////////////////////////////////////////////////////////////

TOKEN == mots qui seront interprétés plus tard.
TOCKENS stockés dans un char** (ft_get_tokens).

/********************************************************************/

/* Check if there are quotes */
while (str[i])


char**    ft_get_tokens(char *str)
{
    // get ride of isspace at the beggining && and the end of the string 
    // ++ get ride of isspace at the beggining and at the end of each tokens
    // -> str_trim ? 
    // Handle multiple pipes
}

check if there are pipe into quote 