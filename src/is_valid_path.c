/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:17:55 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/24 00:18:21 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move(t_map *map, size_t x, size_t y)
{
	size_t	tmp_x;
	size_t	tmp_y;
	size_t	tmp;

	// 枠外
	if (y < 0 || y >= map->count_column || x < 0 || x >= map->count_row)
	{
		ft_printf("false\n");
		return ;
	}
	// 壁に当たった場合
	if (map->map[y][x] == '1')
	{
		ft_printf("wall\n");
		return ;
	}
	if (map->map[y][x] == '3')
	{
		ft_printf("PASSED\n");
		return ;
	}
	if (map->map[y][x] == 'E')
	{
		ft_printf("EXIT\n");
		map->count_exit--;
	}
	if (map->map[y][x] == 'C')
	{
		ft_printf("COLLECTION\n");
		map->count_collection--;
	}
	if (map->count_exit == 0 && map->count_collection == 0)
	{
		ft_printf("VALID\n");
		map->valid_flag = true;
		return ;
	}
	tmp = map->map[y][x];
	map->map[y][x] = '3';

	// 上に移動
	tmp_x = x;
	tmp_y = y - 1;
	if (tmp_y >= 0)
	{
		if (map->map[tmp_y][tmp_x] != '1' && map->map[tmp_y][tmp_x] != '3')
		{
			printf("上\n");
			move(map, tmp_x, tmp_y);
		}
	}

	// 下に移動
	tmp_x = x;
	tmp_y = y + 1;
	if (tmp_y < map->count_column)
	{
		if (map->map[tmp_y][tmp_x] != '1' && map->map[tmp_y][tmp_x] != '3')
		{
			printf("下\n");
			move(map, tmp_x, tmp_y);
		}
	}
	// 右に移動
	tmp_x = x + 1;
	tmp_y = y;
	if (tmp_x < map->count_row)
	{
		if (map->map[tmp_y][tmp_x] != '1' && map->map[tmp_y][tmp_x] != '3')
		{
			printf("右\n");
			move(map, tmp_x, tmp_y);
		}
	}
	// 左に移動
	tmp_x = x - 1;
	tmp_y = y;
	if (tmp_x >= 0)
	{
		if (map->map[tmp_y][tmp_x] != '1' && map->map[tmp_y][tmp_x] != '3')
		{
			printf("左\n");
			move(map, tmp_x, tmp_y);
		}
	}
	// map->map[y][x] = tmp;
}

bool	is_valid_path(t_game_data *data)
{
	t_map	check_valid_map;

	check_valid_map = *(data->map);
	move(&check_valid_map, data->player.x_coordinate, \
			data->player.y_coordinate);
	if (check_valid_map.valid_flag == false)
	{
		ft_printf("false\n");
	}
	return (true);
}
