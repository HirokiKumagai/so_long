/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:29:31 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/28 15:25:04 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_full_collection_count(t_game_data *data)
{
	size_t	max_collection_count;
	size_t	get_collection_count;

	if (data->map->map[data->player.y_point][data->player.x_point] \
		== COLLECTION)
	{
		data->player.get_collection_count++;
		data->map->map[data->player.y_point][data->player.x_point] \
		= GROUND;
	}
	max_collection_count = data->map->count_collection;
	get_collection_count = data->player.get_collection_count;
	if (max_collection_count == get_collection_count)
	{
		data->map->map[data->exit.y_point][data->exit.x_point] = \
		EXIT_OPEN;
		get_put_image(data, EXIT_OPEN, data->exit.x_point, \
				data->exit.y_point);
	}
	return ;
}

static void	replace_map_before_moving(t_game_data *data, char c)
{
	get_put_image(data, c, data->player.x_point, data->player.y_point);
	if (c == EXIT_CLOSE || c == EXIT_OPEN)
		data->map->count_exit--;
	if (data->map->count_exit == 0 && (c == EXIT_CLOSE || c == EXIT_OPEN))
	{
		get_put_image(data, GROUND, data->player.x_point, \
				data->player.y_point);
		data->map->map[data->player.y_point][data->player.x_point] \
				= GROUND;
	}
	else if (data->map->count_exit == 0 && (c != EXIT_CLOSE || c != EXIT_OPEN))
	{
		get_put_image(data, EXIT_CLOSE, data->player.x_point, \
				data->player.y_point);
		data->map->map[data->exit.y_point][data->exit.x_point] = \
		EXIT_CLOSE;
		data->map->count_exit++;
	}
	else if (data->map->count_exit != 0 && (c != EXIT_CLOSE || c != EXIT_OPEN))
	{
		get_put_image(data, GROUND, data->player.x_point, \
				data->player.y_point);
		data->map->map[data->player.y_point][data->player.x_point] \
		= GROUND;
	}
}

static void	process_move_map(t_game_data *data, int direction)
{
	if (direction == UP || direction == KEY_W_UP)
		data->player.y_point -= 1;
	if (direction == DOWN || direction == KEY_S_DOWN)
		data->player.y_point++;
	if (direction == RIGHT || direction == KEY_D_RIGHT)
		data->player.x_point++;
	if (direction == LEFT || direction == KEY_A_LEFT)
		data->player.x_point -= 1;
}

static void	replace_map_after_moving(t_game_data *data, int direction)
{
	if (direction == UP || direction == KEY_W_UP)
		data->player.image = P_BACK_IMG;
	if (direction == DOWN || direction == KEY_S_DOWN)
		data->player.image = P_FRONT_IMG;
	if (direction == RIGHT || direction == KEY_D_RIGHT)
		data->player.image = P_RIGHT_IMG;
	if (direction == LEFT || direction == KEY_A_LEFT)
		data->player.image = P_LEFT_IMG;
	get_put_image(data, PLAYER, data->player.x_point, \
			data->player.y_point);
	data->map->map[data->player.y_point][data->player.x_point] = \
	PLAYER;
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
	if (c == EXIT_OPEN)
	{
		ft_printf("GOAL!!!!\n");
		end_window(data);
	}
	return (true);
}
