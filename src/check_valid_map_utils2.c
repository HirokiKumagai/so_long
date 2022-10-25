/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:25:06 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/25 14:36:49 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	search_player_and_exit(t_game_data*data, t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->count_column)
	{
		x = 0;
		while (x < map->count_row)
		{
			if (map->map[y][x] == 'P')
			{
				data->player.x_coordinate = x;
				data->player.y_coordinate = y;
			}
			else if (map->map[y][x] == 'E')
			{
				data->exit.x_coordinate = x;
				data->exit.y_coordinate = y;
			}
			x++;
		}
		y++;
	}
}

void	fill_in_map(t_game_data *data, t_map *map)
{
	size_t	i;
	char	**lines;
	char	**tmp;

	map->map = (char **)malloc(sizeof(char *) * (map->count_column + 1));
	if (!map->map)
		ft_exit_and_print_error("ERROR!!! no memory...");
	lines = ft_split(map->map_element, '\n');
	if (lines == NULL)
		ft_exit_and_print_error("ERROR!!! no memory...");
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
