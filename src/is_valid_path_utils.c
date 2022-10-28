/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:17:55 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/28 15:16:51 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_map *map, size_t x, size_t y)
{
	size_t	move_after_x;
	ssize_t	move_after_y;

	move_after_x = x;
	move_after_y = y - 1;
	if (move_after_y >= 0)
	{
		if (map->map[move_after_y][move_after_x] != WALL && \
			map->map[move_after_y][move_after_x] != '3')
			move(map, move_after_x, (size_t)move_after_y);
	}
}

void	move_down(t_map *map, size_t x, size_t y)
{
	size_t	move_after_x;
	size_t	move_after_y;

	move_after_x = x;
	move_after_y = y + 1;
	if (move_after_y < map->count_column)
	{
		if (map->map[move_after_y][move_after_x] != WALL && \
			map->map[move_after_y][move_after_x] != '3')
			move(map, move_after_x, move_after_y);
	}
}

void	move_right(t_map *map, size_t x, size_t y)
{
	size_t	move_after_x;
	size_t	move_after_y;

	move_after_x = x + 1;
	move_after_y = y;
	if (move_after_x < map->count_row)
	{
		if (map->map[move_after_y][move_after_x] != WALL && \
			map->map[move_after_y][move_after_x] != '3')
			move(map, move_after_x, move_after_y);
	}
}

void	move_left(t_map *map, size_t x, size_t y)
{
	ssize_t	move_after_x;
	size_t	move_after_y;

	move_after_x = x - 1;
	move_after_y = y;
	if (move_after_x >= 0)
	{
		if (map->map[move_after_y][move_after_x] != WALL && \
			map->map[move_after_y][move_after_x] != '3')
			move(map, (size_t)move_after_x, move_after_y);
	}
}
