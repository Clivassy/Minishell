/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_open.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:03:26 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:03:28 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_print_open_error(t_data *data, char *file_name)
{
	(void)data;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(NULL);
}
