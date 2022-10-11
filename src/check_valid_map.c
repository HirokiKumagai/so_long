/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:26:42 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/11 18:13:50 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_valid_char(char *line)
{
	while (*line != '\0')
	{
		if (*line != '0' && *line != '1' && *line != 'E' \
			&& *line != 'C' && *line != 'P')
			exit(1);
		line++;
	}
	return ;
}

void	check_valid_map(char *map)
{
	char	**lines;
	char	**tmp;

	lines = ft_split(map, '\n');
	tmp = lines;
	while (*lines != NULL)
	{
		check_valid_char(*lines);
		free(*lines);
		*lines = NULL;
		lines++;
	}
	free(tmp);
	return ;
}
