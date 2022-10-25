/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:25:49 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/25 13:54:00 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_VALID_MAP_H
# define CHECK_VALID_MAP_H
# define PASSED 3

t_map	*check_valid_map(t_game_data *data, t_map *map);
bool	is_valid_char(t_map *map);
bool	is_valid_shape(t_map *map);
bool	is_valid_sides(t_map *map, size_t count_column, \
						size_t count_row, char *line);
bool	is_map_closed(t_map *map);
bool	is_valid_map_element(t_map *map);
void	move_up(t_map *map, size_t x, size_t y);
void	move_down(t_map *map, size_t x, size_t y);
void	move_right(t_map *map, size_t x, size_t y);
void	move_left(t_map *map, size_t x, size_t y);
void	move(t_map *map, size_t x, size_t y);
bool	is_valid_path(t_game_data *data);
#endif
