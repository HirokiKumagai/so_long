/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:34:12 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/21 13:29:13 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	end_window(t_game_data *data)
{
	size_t	i;

	free(data->map->map_element);
	free(data->map);
	i = 0;
	while (i < data->map->count_column)
	{
		free(data->map->map[i]);
		i++;
	}
	free(data->map->map[i]);
	free(data->map->map);
	mlx_destroy_window(data->mlx->mlx_id, data->mlx->win);
	system("leaks so_long");
	exit(EXIT_SUCCESS);
}

bool	is_place_after_moving(int direction, t_game_data *data, char c)
{
	t_player	tmp;

	tmp = data->player;
	if (direction == UP || direction == KEY_W_UP)
		tmp.y_coordinate -= 1;
	if (direction == DOWN || direction == KEY_S_DOWN)
		tmp.y_coordinate++;
	if (direction == RIGHT || direction == KEY_A_LEFT)
		tmp.x_coordinate++;
	if (direction == LEFT || direction == KEY_D_RIGHT)
		tmp.x_coordinate -= 1;
	if (data->map->map[tmp.y_coordinate][tmp.x_coordinate] == c)
		return (true);
	return (false);
}

int	process_player_action(int direction, t_game_data *data)
{
	if (is_place_after_moving(direction, data, '1'))
		return (false);
	else if (is_place_after_moving(direction, data, '0'))
		return (move_player(direction, data, '0'));
	else if (is_place_after_moving(direction, data, 'E'))
		return (move_player(direction, data, 'E'));
	else if (is_place_after_moving(direction, data, 'O'))
		return (move_player(direction, data, 'O'));
	else if (is_place_after_moving(direction, data, 'C'))
		return (move_player(direction, data, '0'));
	return (false);
}

int	key_hook(int keycode, t_game_data *data)
{
	if (keycode == ESC)
		end_window(data);
	if (keycode == UP || keycode == KEY_W_UP)
		process_player_action(UP, data);
	if (keycode == DOWN || keycode == KEY_S_DOWN)
		process_player_action(DOWN, data);
	if (keycode == LEFT || keycode == KEY_A_LEFT)
		process_player_action(LEFT, data);
	if (keycode == RIGHT || keycode == KEY_D_RIGHT)
		process_player_action(RIGHT, data);
	return (0);
}
