/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:25:49 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/17 02:16:26 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_VALID_MAP_H
# define CHECK_VALID_MAP_H

void	check_valid_map(t_map *map);
void	check_valid_char(t_map *map);
void	check_map_valid_shape(t_map *map);
void	check_map_sides(t_map *map, size_t count_column, \
						size_t count_row, char *line);
void	check_map_closed(t_map *map);
void	check_valid_map_element(t_map *map);
#endif
