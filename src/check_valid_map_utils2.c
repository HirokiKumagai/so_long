/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:25:06 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/28 15:24:35 by hkumagai         ###   ########.fr       */
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
			if (map->map[y][x] == PLAYER)
			{
				data->player.x_point = x;
				data->player.y_point = y;
			}
			else if (map->map[y][x] == EXIT_CLOSE)
			{
				data->exit.x_point = x;
				data->exit.y_point = y;
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
		ft_exit_and_print_error("Error\nno memory...");
	lines = ft_split(map->map_element, '\n');
	if (lines == NULL)
		ft_exit_and_print_error("Errro\nno memory...");
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

bool	is_valid_map_size(t_game_data *data)
{
	int	*x;
	int	*y;

	x = (int *)malloc(sizeof(int *));
	if (!x)
		ft_exit_and_print_error("Error\nno memory...");
	y = (int *)malloc(sizeof(int *));
	if (!y)
		ft_exit_and_print_error("Error\nno memory...");
	mlx_get_screen_size(data->mlx->mlx_id, x, y);
	if ((int)(data->map->count_column) * 32 > *y || \
	(int)(data->map->count_row) * 32 > *x)
	{
		free(x);
		free(y);
		return (ft_print_error("Error\ninvalid map size!"));
	}
	free(x);
	free(y);
	return (true);
}
