/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 00:28:21 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/25 14:36:04 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	ft_print_error(char *message)
{
	ft_printf("%s\n", message);
	return (false);
}

void	ft_exit_and_print_error(char *message)
{
	ft_printf("%s\n", message);
	exit (EXIT_FAILURE);
}
