/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:34:51 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/28 15:24:35 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# define WALL '1'
# define GROUND '0'
# define COLLECTION 'C'
# define EXIT_CLOSE 'E'
# define EXIT_OPEN 'O'
# define PLAYER 'P'

typedef struct s_mlx_data
{
	void	*mlx_id;
	void	*win;
}	t_mlx_data;

typedef struct s_player
{
	int		direction;
	int		x_point;
	int		y_point;
	size_t	steps_count;
	size_t	get_collection_count;
	char	*image;
}	t_player;

typedef struct s_exit
{
	int		x_point;
	int		y_point;
	bool	is_open;
}	t_exit;

typedef struct s_map_data
{
	void	*mlx;
	void	*win;
	char	*map_element;
	char	**map;
	bool	valid_flag;
	size_t	count_column;
	size_t	count_row;
	size_t	count_exit;
	size_t	count_player;
	size_t	count_collection;
	int		*max_height;
	int		*max_width;
}	t_map;

typedef struct s_game_data
{
	t_mlx_data	*mlx;
	t_map		*map;
	t_player	player;
	t_exit		exit;
}	t_game_data;
#endif
