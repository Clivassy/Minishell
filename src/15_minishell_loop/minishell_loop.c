#include "minishell.h"

// get cmd
// exec

int	ft_get_cmd(t_data *data)
{
	int	error_status_parser;

	ft_lexer(data);
	error_status_parser = ft_parser(data); // ajouter empty list fct dans parser + heredoc?
	if (error_status_parser != 0)
		ft_print_error(data, error_status_parser);
	else
	{
		ft_group_tokens(data);
		ft_create_exec_elm_list(data);
	}
}

void	ft_minishell_loop(t_data *data)
{
	int	error_status;

	error_status = 0;
        while (data->exit_asked == 1)
        {
            data->read_line  = readline("minishell> "); // ajouter secu fct
			error_status = ft_get_cmd(data);
			if (error_status != 0)
				ft_print_error(data, error_status);
			else
				ft_exec_cmd(data);
        }
	// faire fonction de free intermediaire + reinit de readline et data comme au debut
}
