/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:57:16 by jbatoro           #+#    #+#             */
/*   Updated: 2022/07/16 09:57:45 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argv;
	if (!isatty(0))
	{
		ft_printf("error: bad standard input\n");
		return (0);
	}
	if (argc != 1)
	{
		ft_printf("error: invalid number of arguments\n");
		return (0);
	}
	ft_initialisation(&data, envp);
	ft_minishell_loop(&data);
	ft_free_garbage_collector(&data);
	return (0);
}
