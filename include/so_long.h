/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:25:57 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/25 14:21:33 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// key_event
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define KEY_W_UP 119
# define KEY_S_DOWN 115
# define KEY_A_LEFT 97
# define KEY_D_RIGHT 100
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/gnl/include/get_next_line_bonus.h"
# include "../lib/libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "./object.h"
# include "./errors.h"
# include "./load_map.h"
# include "./check_valid_map.h"
# include "./display_to_window.h"

int		end_window(t_game_data *data);
void	check_full_collection_count(t_game_data *data);
int		move_player(int direction, t_game_data *data, char c);
bool	is_place_after_moving(int direction, t_game_data *data, char c);
int		process_player_action(int direction, t_game_data *data);
int		key_hook(int keycode, t_game_data *data);
#endif
