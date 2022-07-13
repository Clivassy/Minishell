#include "minishell.h"

void	ft_print_error(t_data *data, int error_status)
{
	if (error_status == SYNTAX_ERR_PIPE)
		ft_printf("bash: syntax error near unexpected token `|'\n");
	else if (error_status == SYNTAX_ERR_REDIRECT_IN)
		ft_printf("bash: syntax error near unexpected token `<'\n");
	else if (error_status == SYNTAX_ERR_REDIRECT_OUT)
		ft_printf("bash: syntax error near unexpected token `>'\n");
	else if (error_status == SYNTAX_ERR_D_REDIRECT_OUT)
		ft_printf("bash: syntax error near unexpected token `>>'\n");
	else if (error_status == SYNTAX_ERR_NEWLINE)
		ft_printf("bash: syntax error near unexpected token `newline'\n");
	else if (error_status == SYNTAX_ERR_HEREDOC)
		ft_printf("bash: syntax error near unexpected token `<<'\n");
	else if (error_status == TAB_OR_SPC_ERR)
		ft_printf("\0");
	else if (error_status == EXIT_CODE_CTRLC_HEREDOC)
		ft_printf("\0");
	else if (error_status == UNCLOSED_QUOTES_ERR)
		ft_printf("bash: syntax error: expected closing quote\n");
	else
		ft_printf("NUMBER = %d\n error detected, unknown status\n", error_status);
}
