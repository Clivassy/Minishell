#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


Commandes OK
cmd > cmd
cmd > fichier 



// LEXER 
/* 
- Premier checck : input valid ? 
- Decoupe l'input en "mots" (a nous de defiir ce qu'on entend par "mot" == tokens)
- Parse l'input (pas d'interpretation a ce stade)
- Definir comment parser : 
-> Stockés dans tab of tokens (ft_get_tokens)

- On recupere la string entree en input avec readline et je la divise en token selon les regles (regles a definir)


TOKENS = liste chainee
TOKEN[0] = 


*/

// PARSER// 
/*
- Recupere une liste de tokens && va interpreter le sens
- 
*/
/*int main()
{
    printf( "%s\n", readline( "minishell> " ) );
    return 0;
}*/

// EXEC 
int main(int ac, char **av)
{
    const char *ptr;
    while (temp == 0)
    {
        ft_printf("minishell>");
        ptr = readline(ptr);
    }
    return (0);
 // boucle infinie : lance le script   
}


