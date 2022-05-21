/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:25:25 by ybellot           #+#    #+#             */
/*   Updated: 2022/05/21 16:45:25 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// check if str == "-n"
static int	ft_is_n_flag(char *str)
{
	if (ft_strlen(str) == 2)
		if (str[0] == '-' && str[1] == 'n')
			return (1);
	return (0);
}

static void	ft_print_arguments_list(char **arguments_list)
{
	int	i;
	int	first_arg;

	i = 0;
	first_arg = 1;
	while (arguments_list[i])
	{
		if (first_arg)
			first_arg = 0;
		else
			ft_printf(" ");
		ft_printf("%s", arguments_list[i]);
		i++;
	}
}

void	ft_echo(char **arguments_list)
{
	int	_flag_found;
	int	print_begin;

	if (!arguments_list || !arguments_list[0])
		return ;
	if (ft_is_n_flag(arguments_list[0]))
	{
		n_flag_found = 1;
		print_begin = 1;
	}
	else
	{
		n_flag_found = 0;
		print_begin = 0;
	}
	ft_print_arguments_list(&(arguments_list[print_begin]));
	if (!n_flag_found)
		ft_printf("\n");
}

// version coherente avec zsh
// void    ft_echo(char **arguments_list)
// {
//     int n_flag_found;
//     int first_arg;
//     int i;

//     if (!arguments_list)
//         return;
//     n_flag_found = 0;
//     first_arg = 1;
//     i = 0;
//     while (arguments_list[i])
//     {
//         if (!n_flag_found && ft_is_n_flag(arguments_list[i]))
//             n_flag_found = 1;
//         else
//         {
//             if (first_arg)
//                 first_arg = 0;
//             else
//                 ft_printf(" ");
//             ft_printf("%s", arguments_list[i]);
//         }
//         i++;
//     }
//     if (!n_flag_found)
//         ft_printf("\n");
// }
