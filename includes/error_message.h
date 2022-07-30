/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:14:49 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:14:52 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define SYNTAX_ERR_PIPE 1
# define SYNTAX_ERR_REDIRECT_IN 2
# define SYNTAX_ERR_REDIRECT_OUT 3
# define SYNTAX_ERR_D_REDIRECT_OUT 4
# define SYNTAX_ERR_NEWLINE 5
# define SYNTAX_ERR_HEREDOC 6
# define UNCLOSED_QUOTES_ERR 7
# define TAB_OR_SPC_ERR 8

# define EXIT_CODE_NO_SUCH_FILE_OR_DIR 127
# define EXIT_CODE_COMMAND_NOT_FOUND 127
# define EXIT_CODE_CTRLC_HEREDOC 130

#endif
