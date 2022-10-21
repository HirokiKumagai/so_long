/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:29:31 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/21 14:57:37 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_full_collection_count(t_game_data *data)
{
	size_t	max_collection_count;
	size_t	get_collection_count;

	if (data->map->map[data->player.y_coordinate][data->player.x_coordinate] \
		== 'C')
	{
		data->player.get_collection_count++;
		data->map->map[data->player.y_coordinate][data->player.x_coordinate] \
		= '0';
	}
	max_collection_count = data->map->count_collection;
	get_collection_count = data->player.get_collection_count;
	if (max_collection_count == get_collection_count)
	{
		data->map->map[data->exit.y_coordinate][data->exit.x_coordinate] = 'O';
		get_put_image(data, 'O', data->exit.x_coordinate, \
				data->exit.y_coordinate);
		return (true);
	}
	return (false);
}

static void	replace_map_before_moving(t_game_data *data, char c)
{
	get_put_image(data, c, data->player.x_coordinate, \
			data->player.y_coordinate);
	if (c == 'E' || c == 'O')
		data->map->count_exit--;
	if (data->map->count_exit == 0 && (c == 'E' || c == 'O'))
	{
		get_put_image(data, '0', data->player.x_coordinate, \
				data->player.y_coordinate);
		data->map->map[data->player.y_coordinate][data->player.x_coordinate] \
				= '0';
	}
	else if (data->map->count_exit == 0 && (c != 'E' || c != 'O'))
	{
		get_put_image(data, 'E', data->player.x_coordinate, \
				data->player.y_coordinate);
		data->map->map[data->exit.y_coordinate][data->exit.x_coordinate] = 'E';
		data->map->count_exit++;
	}
	else if (data->map->count_exit != 0 && (c != 'E' || c != 'O'))
	{
		get_put_image(data, '0', data->player.x_coordinate, \
				data->player.y_coordinate);
		data->map->map[data->player.y_coordinate][data->player.x_coordinate] \
				= '0';
	}
}

static void	process_move_map(t_game_data *data, int direction)
{
	if (direction == UP || direction == KEY_W_UP)
		data->player.y_coordinate -= 1;
	if (direction == DOWN || direction == KEY_S_DOWN)
		data->player.y_coordinate++;
	if (direction == RIGHT || direction == KEY_D_RIGHT)
		data->player.x_coordinate++;
	if (direction == LEFT || direction == KEY_A_LEFT)
		data->player.x_coordinate -= 1;
}

static void	replace_map_after_moving(t_game_data *data, int direction)
{
	if (direction == UP || direction == KEY_W_UP)
		data->player.image = P_BACK;
	if (direction == DOWN || direction == KEY_S_DOWN)
		data->player.image = P_FRONT;
	if (direction == RIGHT || direction == KEY_D_RIGHT)
		data->player.image = P_RIGHT;
	if (direction == LEFT || direction == KEY_A_LEFT)
		data->player.image = P_LEFT;
	get_put_image(data, 'P', data->player.x_coordinate, \
			data->player.y_coordinate);
	data->map->map[data->player.y_coordinate][data->player.x_coordinate] = 'P';
}

int	move_player(int direction, t_game_data *data, char c)
{
	(void)direction;
	replace_map_before_moving(data, c);
	process_move_map(data, direction);
	check_full_collection_count(data);
	replace_map_after_moving(data, direction);
	data->player.steps_count++;
	ft_printf("%d\n", data->player.steps_count);
	if (c == 'O')
	{
		ft_printf("GOAL!!!!\n");
		end_window(data);
	}
	return (true);
}
