/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:26:42 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/24 01:08:14 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	is_valid_char(t_map *map)
{
	char	**lines;
	char	*line;
	char	**tmp;

	lines = ft_split(map->map_element, '\n');
	if (lines == NULL)
		return (ft_print_error("no memory"));
	tmp = lines;
	while (*lines != NULL)
	{
		line = *lines;
		while (*line != '\0')
		{
			if (*line != '0' && *line != '1' && *line != 'E' \
				&& *line != 'C' && *line != 'P')
				return (ft_print_error("invalid char"));
			line++;
		}
		free(*lines);
		*lines = NULL;
		lines++;
	}
	free(tmp);
	return (true);
}

bool	is_valid_shape(t_map *map)
{
	char	**lines;
	char	*line;
	char	**tmp;
	size_t	count;

	lines = ft_split(map->map_element, '\n');
	if (lines == NULL)
		return (ft_print_error("no memory"));
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
			return (false);
		free(*lines);
		*lines = NULL;
		lines++;
	}
	free(tmp);
	return (true);
}

bool	is_valid_sides(t_map *map, size_t count_column,
							size_t count_row, char *line)
{
	while (*line != '\0')
	{
		if ((count_column == 0 || count_column == map->count_column - 1) \
			&& *line != '1')
			return (false);
		else if ((count_row == 0 || count_row == map->count_row - 1) \
			&& *line != '1')
			return (false);
		count_row++;
		line++;
	}
	return (true);
}

bool	is_map_closed(t_map *map)
{
	char	**lines;
	char	*line;
	char	**tmp;
	size_t	count_column;
	size_t	count_row;

	lines = ft_split(map->map_element, '\n');
	if (lines == NULL)
		return (ft_print_error("no memory"));
	tmp = lines;
	count_column = 0;
	while (*lines != NULL)
	{
		line = *lines;
		count_row = 0;
		if (!is_valid_sides(map, count_column, count_row, line))
			return (ft_print_error("invalid map sides"));
		count_column++;
		free(*lines);
		*lines = NULL;
		lines++;
	}
	free(tmp);
	return (true);
}

bool	is_valid_map_element(t_map *map)
{
	if (map->count_exit != 1 && map->count_player != 1)
		return (ft_print_error("invalid count of exit and player"));
	if (map->count_exit != 1)
		return (ft_print_error("invalid count of exit"));
	if (map->count_player != 1)
		return (ft_print_error("invalid count of player"));
	if (map->count_collection < 1)
		return (ft_print_error("not enough collections"));
	return (true);
}
