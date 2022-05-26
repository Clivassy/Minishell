#include "minishell.h"

/*----------------------------------------------------------------
Break the string input into a char **.
Each bloc is broken by metacharacter such as : $, |, ", ' and space.
If a space is followed by other spaces, only one space will be take into
account.
-----------------------------------------------------------------*/
void    ft_parse_quote(t_data *input)
{
    int i;

    i = 0;
    while (input->read_line[i])
    {
        if (input->read_line[i] == ' ')
            input->command_list[i][0] = ' ';
        while (input->read_line[i] == ' '
               || input->read_line[i] == '\t')
            i++;
        if (input->read_line[i] == '"' 
            || input->read_line[i] == '\'')
        {
            // fonction qui va recupérer ce qui est entre quotes
            // 
        }
        i++;
    }
}
