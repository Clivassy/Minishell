#include "minishell.h"

int ft_is_space(t_data *data, char *read_line, int index)
{
    char *space_token;
    t_token *space;

    if (read_line[index] == ' ' && read_line[index -1] != ' ')
    {
        space_token = ft_substr(read_line, index, 1);
        ft_add_to_garbage_collector(data, space_token);
        if (!space_token)
            return (-1); // ft_exit 
        space = ft_new_token(space_token, T_SPACE);
        ft_lstadd_back_token(&data->tokens_list, space);
    }
    return (0);
}

int ft_is_redirect(t_data *data, char *read_line, int index)
{
    char *separator;
    t_token *separator_token;

    if (ft_is_double_redirect(read_line, index,read_line[index]))
    {
        separator = ft_substr(read_line, index, 2);
        ft_add_to_garbage_collector(data, separator);
        if (read_line[index] == '>')
            separator_token = ft_new_token(separator, D_REDIRECT_OUT);
        else 
            separator_token = ft_new_token(separator, T_HEREDOC);
        ft_lstadd_back_token(&data->tokens_list, separator_token);
    }
    else
    {
        separator = ft_substr(read_line, index, 1);
        ft_add_to_garbage_collector(data, separator);
        if (read_line[index] == '<')
            separator_token = ft_new_token(separator, T_REDIRECT_IN);
        else
            separator_token = ft_new_token(separator, T_REDIRECT_OUT);
        ft_lstadd_back_token(&data->tokens_list, separator_token);
    }
    return (0);
}

int ft_others_separators(t_data *data, char letter, char *sep)
{
    t_token *separator_token;

    if (letter == '|')
        separator_token = ft_new_token(sep, T_PIPE);
    ft_lstadd_back_token(&data->tokens_list, separator_token);
    return (0);
}

int ft_get_separators(t_data *data, int index)
{
    char *separator;
    char *line;
    t_token *separator_token;

    line = data->read_line;
    if (line[index] == ' ')
        ft_is_space(data, line, index);
    if (line[index] == '<' || line[index] == '>')
    {
        ft_is_redirect(data, line, index);
            if (ft_is_double_redirect(line, index, line[index]))   
        return (1);
    }      
    if (line[index] == '|')
    {
        separator = ft_substr(line, index, 1);
        ft_add_to_garbage_collector(data, separator);
        if (!separator)
            return (-1);
        ft_others_separators(data, line[index], separator);
    }
    return(0);
}