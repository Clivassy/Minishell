/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:11:00 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 10:11:02 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_builtin_pwd(t_data *data, char **cmd)
{
	char	*path;

	(void)cmd;
	path = NULL;
	path = getcwd(path, 0);
	if (!path)
		return (ft_pwd_error(data));
	ft_add_to_garbage_collector(data, path);
	ft_printf("%s\n", path);
	ft_free(data, path);
	return (0);
}
