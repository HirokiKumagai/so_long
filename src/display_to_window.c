/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_to_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:29:21 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/24 02:29:15 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	to_window_and_destroy_img(t_game_data *data, \
										int x, int y, void *mlx_img)
{
	mlx_put_image_to_window(data->mlx->mlx_id, data->mlx->win, \
							mlx_img, x * 32, y * 32);
	mlx_destroy_image(data->mlx->mlx_id, mlx_img);
}

void	get_put_image(t_game_data *data, char c, int x, int y)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;

	mlx_img = NULL;
	if (c == '1')
		mlx_img = mlx_xpm_file_to_image(data->mlx->mlx_id, \
					(char *)WALL, &img_width, &img_height);
	else if (c == '0')
		mlx_img = mlx_xpm_file_to_image(data->mlx->mlx_id, \
					(char *)GROUND, &img_width, &img_height);
	else if (c == 'C')
		mlx_img = mlx_xpm_file_to_image(data->mlx->mlx_id, \
					(char *)COLLECT, &img_width, &img_height);
	else if (c == 'P')
		mlx_img = mlx_xpm_file_to_image(data->mlx->mlx_id, \
					data->player.image, &img_width, &img_height);
	else if (c == 'E')
		mlx_img = mlx_xpm_file_to_image(data->mlx->mlx_id, \
					(char *)EXIT_CLOSE, &img_width, &img_height);
	else if (c == 'O')
		mlx_img = mlx_xpm_file_to_image(data->mlx->mlx_id, \
					(char *)EXIT_OPEN, &img_width, &img_height);
	to_window_and_destroy_img(data, x, y, mlx_img);
}

int	display_map(t_game_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < data->map->count_column)
	{
		x = 0;
		while (x < data->map->count_row)
		{
			get_put_image(data, data->map->map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (0);
}
