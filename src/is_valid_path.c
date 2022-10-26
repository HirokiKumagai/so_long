/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:17:55 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/26 14:55:14 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	is_end(t_map *map, size_t x, size_t y)
{
	if (y >= map->count_column || x >= map->count_row)
		return (false);
	if (map->map[y][x] == '1')
		return (false);
	if (map->map[y][x] == '3')
		return (false);
	if (map->map[y][x] == 'E')
		map->count_exit--;
	if (map->map[y][x] == 'C')
		map->count_collection--;
	if (map->count_exit == 0 && map->count_collection == 0)
	{
		map->valid_flag = true;
		return (false);
	}
	return (true);
}

void	move(t_map *map, size_t x, size_t y)
{
	if (!is_end(map, x, y))
		return ;
	map->map[y][x] = '3';
	move_up(map, x, y);
	move_down(map, x, y);
	move_right(map, x, y);
	move_left(map, x, y);
}

static void	ft_free_dup(char **src)
{
	char	**tmp;
	size_t	count;
	size_t	i;

	count = 0;
	tmp = src;
	while (*tmp != NULL)
	{
		count++;
		tmp++;
	}
	i = 0;
	tmp = src;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
}

static char	**ft_dup(char **src)
{
	char	**dst;
	char	**tmp;
	size_t	count;

	count = 0;
	tmp = src;
	while (*tmp != NULL)
	{
		count++;
		tmp++;
	}
	dst = (char **)malloc(sizeof(char *) * (count + 1));
	if (dst == NULL)
		return (NULL);
	tmp = src;
	count = 0;
	while (*tmp != NULL)
	{
		dst[count] = ft_strdup(*tmp);
		tmp++;
		count++;
	}
	return (dst);
}

bool	is_valid_path(t_game_data *data)
{
	t_map	tmp_map;

	tmp_map = *(data->map);
	tmp_map.map = ft_dup(tmp_map.map);
	move(&tmp_map, data->player.x_coordinate, \
			data->player.y_coordinate);
	if (!tmp_map.valid_flag)
	{
		ft_free_dup(tmp_map.map);
		return (ft_print_error("ERROR!!! invalid path."));
	}
	ft_free_dup(tmp_map.map);
	return (true);
}
