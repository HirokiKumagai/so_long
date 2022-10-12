/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:26:42 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/12 16:40:55 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_valid_char(char *map)
{
	char	**lines;
	char	*line;
	char	**tmp;

	lines = ft_split(map, '\n');
	tmp = lines;
	while (*lines != NULL)
	{
		line = *lines;
		while (*line != '\0')
		{
			if (*line != '0' && *line != '1' && *line != 'E' \
				&& *line != 'C' && *line != 'P')
				exit(1);
			line++;
		}
		free(*lines);
		*lines = NULL;
		lines++;
	}
	free(tmp);
	return ;
}

void	check_valid_map(char *map)
{
	check_valid_char(map);
	return ;
}
