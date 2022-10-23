/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:25:06 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/23 22:00:43 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	tmp(t_game_data *data, char *str, int x, int y)
{
	if (*str == 'P')
	{
		data->player.x_coordinate = x;
		data->player.y_coordinate = y;
	}
	else if (*str == 'E')
	{
		data->exit.x_coordinate = x;
		data->exit.y_coordinate = y;
	}
	return ;
}

void	search_player_and_exit(t_game_data*data, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->count_column)
	{
		j = 0;
		while (j < map->count_row)
		{
			tmp(data, &map->map[i][j], j, i);
			j++;
		}
		i++;
	}
}

void	fill_in_map(t_game_data *data, t_map *map)
{
	size_t	i;
	char	**lines;
	char	**tmp;

	map->map = (char **)malloc(sizeof(char *) * (map->count_column + 1));
	if (!map->map)
		exit(1);
	lines = ft_split(map->map_element, '\n');
	if (lines == NULL)
		exit(1);
	tmp = lines;
	i = 0;
	while (*lines != NULL)
	{
		map->map[i] = *lines;
		lines++;
		i++;
	}
	map->map[i] = NULL;
	free(tmp);
	data->map = map;
	return ;
}
