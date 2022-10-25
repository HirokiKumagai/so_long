/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_to_window.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:37:18 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/24 01:23:10 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_TO_WINDOW_H
# define DISPLAY_TO_WINDOW_H

# define WALL "imgs/block.xpm"
# define GROUND "imgs/background.xpm"
# define COLLECT "imgs/collection.xpm"
# define EXIT_CLOSE "imgs/no_goal.xpm"
# define EXIT_OPEN "imgs/goal_in.xpm"
# define P_BACK "imgs/player_normal.xpm"
# define P_FRONT "imgs/player_normal.xpm"
# define P_LEFT "imgs/player_left.xpm"
# define P_RIGHT "imgs/player_right.xpm"

int		display_map(t_game_data *data);
void	get_put_image(t_game_data *data, char c, int x, int y);
#endif
