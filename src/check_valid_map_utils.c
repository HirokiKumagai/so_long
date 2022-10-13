/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:26:42 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/13 23:15:23 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_valid_char(t_map *map)
{
	char	**lines;
	char	*line;
	char	**tmp;

	lines = ft_split(map->map_element, '\n');
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

void	check_map_valid_shape(t_map *map)
{
	char	**lines;
	char	*line;
	char	**tmp;
	size_t	count;

	lines = ft_split(map->map_element, '\n');
	tmp = lines;
	while (*lines != NULL)
	{
		line = *lines;
		count = 0;
		while (*line != '\0')
		{
			count++;
			line++;
		}
		if (count != map->count_row)
			exit(1);
		free(*lines);
		*lines = NULL;
		lines++;
	}
	free(tmp);
	return ;
}

void	check_map_sides(t_map *map, size_t count_column,
							size_t count_row, char *line)
{
	while (*line != '\0')
	{
		if ((count_column == 0 || count_column == map->count_column - 1) \
			&& *line != '1')
			exit(1);
		else if ((count_row == 0 || count_row == map->count_row - 1) \
			&& *line != '1')
			exit(1);
		count_row++;
		line++;
	}
}

void	check_map_closed(t_map *map)
{
	char	**lines;
	char	*line;
	char	**tmp;
	size_t	count_column;
	size_t	count_row;

	lines = ft_split(map->map_element, '\n');
	tmp = lines;
	count_column = 0;
	while (*lines != NULL)
	{
		line = *lines;
		count_row = 0;
		check_map_sides(map, count_column, count_row, line);
		count_column++;
		free(*lines);
		*lines = NULL;
		lines++;
	}
	free(tmp);
	return ;
}

void	check_valid_map_element(t_map *map)
{
	if (map->count_exit != 1 || map->count_player != 1)
		exit(1);
	if (map->count_collection < 1)
		exit(1);
	return ;
}
