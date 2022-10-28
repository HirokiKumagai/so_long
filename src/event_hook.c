/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:34:12 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/28 15:24:35 by hkumagai         ###   ########.fr       */
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
	exit(EXIT_SUCCESS);
}

bool	is_place_after_moving(int direction, t_game_data *data, char c)
{
	t_player	tmp;

	tmp = data->player;
	if (direction == UP || direction == KEY_W_UP)
		tmp.y_point -= 1;
	if (direction == DOWN || direction == KEY_S_DOWN)
		tmp.y_point++;
	if (direction == RIGHT || direction == KEY_A_LEFT)
		tmp.x_point++;
	if (direction == LEFT || direction == KEY_D_RIGHT)
		tmp.x_point -= 1;
	if (data->map->map[tmp.y_point][tmp.x_point] == c)
		return (true);
	return (false);
}

int	process_player_action(int direction, t_game_data *data)
{
	if (is_place_after_moving(direction, data, WALL))
		return (false);
	else if (is_place_after_moving(direction, data, GROUND))
		return (move_player(direction, data, GROUND));
	else if (is_place_after_moving(direction, data, EXIT_CLOSE))
		return (move_player(direction, data, EXIT_CLOSE));
	else if (is_place_after_moving(direction, data, EXIT_OPEN))
		return (move_player(direction, data, EXIT_OPEN));
	else if (is_place_after_moving(direction, data, COLLECTION))
		return (move_player(direction, data, GROUND));
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
