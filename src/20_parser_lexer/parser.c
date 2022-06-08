#include "minishell.h"

/*----------------------------- PARSER ------------------------------

3 ) Parsing : lecture analyse des morceaux de phrase stockés dans ma listes chainée de tokens :
-> on va stocker chaque commande dans un char** de notre liste chainée (data ? ou exec?).
(chaque potentielle cmd étant délimitée par un pipe)
-> dans 
----------------------------------------------------------------------*/


        
/*--------------------------------------------------------------------------

NB : On part du principe que j'ai extrait le pipe suivant chaque commande 
une commande == ce qui ce situe avant un pipe 
structure de commande ok : 
[heredoc][word][heredoc]
[word][redirect][word][$][word] 

-------------------------------------------------------------------------- 

structure incorrecte :

[pipe][word][redirect]
[space] [redirect]
[space]
[redirect]
[word] [D_redirect_out] [redirect_in]
[heredoc][heredoc]

--------------------------------------------------------------------------*/