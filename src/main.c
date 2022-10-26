/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:08:26 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/26 09:03:34 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	hook(t_game_data *data)
{
	mlx_hook(data->mlx->win, X_EVENT_KEY_PRESS, 1L << 0, key_hook, data);
	mlx_hook(data->mlx->win, X_EVENT_KEY_EXIT, 1L << 0, end_window, data);
	mlx_expose_hook(data->mlx->win, display_map, data->mlx);
	mlx_loop(data->mlx->mlx_id);
	return ;
}

static void	init_data(t_game_data *data)
{
	data->player.direction = 0;
	data->player.get_collection_count = 0;
	data->player.image = P_FRONT;
	data->player.steps_count = 0;
}

int	main(int argc, const char *argv[])
{
	t_mlx_data	vars;
	t_map		*map;
	t_game_data	game_data;

	if (argc != 2)
		ft_exit_and_print_error("ERROR!!! invalid args.");
	init_data(&game_data);
	map = load_map((char *)argv[1]);
	map = check_valid_map(&game_data, map);
	vars.mlx_id = mlx_init();
	game_data.mlx = &vars;
	vars.win = mlx_new_window(vars.mlx_id, \
		map->count_row * 32, map->count_column * 32, "so_long");
	display_map(&game_data);
	hook(&game_data);
	return (0);
}
