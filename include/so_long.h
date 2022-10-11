/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:25:57 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/11 13:08:44 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/gnl/include/get_next_line_bonus.h"
# include "../lib/libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

// 1
#define WALL "imgs/tiles/map_ground_rock.xpm"
// 0
#define GROUND "imgs/tiles/map_ground.xpm"
// C
#define COLLECT "imgs/tiles/map_collect.xpm"
// E
#define EXIT_CLOSE "imgs/exit/map_exit_close.xpm"
#define EXIT_OPEN "imgs/exit/map_exit_open.xpm"
// P
#define P_BACK_1 "imgs/player/map_person_back_1.xpm"
#define P_BACK_2 "imgs/player/map_person_back_2.xpm"
#define P_BACK_3 "imgs/player/map_person_back_3.xpm"
#define P_FRONT_1 "imgs/player/map_person_front_1.xpm"
#define P_FRONT_2 "imgs/player/map_person_front_2.xpm"
#define P_FRONT_3 "imgs/player/map_person_front_3.xpm"
#define P_LEFT_1 "imgs/player/map_person_left_1.xpm"
#define P_LEFT_2 "imgs/player/map_person_left_2.xpm"
#define P_LEFT_3 "imgs/player/map_person_left_3.xpm"
#define P_RIGHT_1 "imgs/player/map_person_right_1.xpm"
#define P_RIGHT_2 "imgs/player/map_person_right_2.xpm"
#define P_RIGHT_3 "imgs/player/map_person_right_3.xpm"

// key_event
#define ESC 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364

// run_player
#define MIDDLE_LEG 25000
#define LEFT_LEG_UP 50000
#define RIGHT_LEG_UP 100000
#define RESET_COUNT 200000

#endif
