/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_to_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:29:21 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/23 21:59:57 by hkumagai         ###   ########.fr       */
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

static void	display_map(t_game_data *data, char *str, int x, int y)
{
	if (*str == '1')
		get_put_image(data, *str, x, y);
	else if (*str == '0')
		get_put_image(data, *str, x, y);
	else if (*str == 'C')
		get_put_image(data, *str, x, y);
	else if (*str == 'P')
	{
		// data->player.x_coordinate = x;
		// data->player.y_coordinate = y;
		get_put_image(data, *str, x, y);
	}
	else if (*str == 'E')
	{
		// data->exit.x_coordinate = x;
		// data->exit.y_coordinate = y;
		get_put_image(data, *str, x, y);
	}
	else if (*str == 'O')
		get_put_image(data, *str, x, y);
}

int	put_map(t_game_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map->count_column)
	{
		j = 0;
		while (j < data->map->count_row)
		{
			display_map(data, &data->map->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (0);
}
