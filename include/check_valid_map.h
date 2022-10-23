/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:25:49 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/24 00:52:51 by hkumagai         ###   ########.fr       */
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
bool	is_valid_path(t_game_data *data);
#endif
