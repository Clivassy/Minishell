#include "minishell.h"

/*----------------------------- PARSER ------------------------------*/

/*******************************************************************/
/* 
- Récuperer la liste de tokens
- Parser les tokens un a un
IF 
- Chercher si il y a des < > ou << >> : strchr 

/********************************************************************/
        
Si dquote ou squote :
    -> Parser et checker si on trouve des pipes au milieu de squotes ou dquotes
        -> Si squote ou dquote non fermées : voir ce qu' on fait (ammon)
        -> Si dquote :
            SI '$': chercher la variable d'environnement et remplace le contenu( a quel moment?)
                -> checker si on trouve des <> <<>> au milieu des quotes
                    -> Si OUI : le resultat == token + dquotes
                    -> Si NON : le resultat == token
        -> Si squote :
            ->checker si on trouve des <> <<>> au milieu des quotes 
                -> Si OUI : le resultat == token + dquotes
                -> Si NON : le resultat == token
Si absence de squote ou dquote :
    -> Parser et découper l'input en fonction des pipes.