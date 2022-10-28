/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_to_window.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:37:18 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/28 15:10:40 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_TO_WINDOW_H
# define DISPLAY_TO_WINDOW_H

# define WALL_IMG "imgs/block.xpm"
# define GROUND_IMG "imgs/background.xpm"
# define COLLECT_IMG "imgs/collection.xpm"
# define EXIT_CLOSE_IMG "imgs/no_goal.xpm"
# define EXIT_OPEN_IMG "imgs/goal_in.xpm"
# define P_BACK_IMG "imgs/player_normal.xpm"
# define P_FRONT_IMG "imgs/player_normal.xpm"
# define P_LEFT_IMG "imgs/player_left.xpm"
# define P_RIGHT_IMG "imgs/player_right.xpm"

int		display_map(t_game_data *data);
void	get_put_image(t_game_data *data, char c, int x, int y);
#endif
