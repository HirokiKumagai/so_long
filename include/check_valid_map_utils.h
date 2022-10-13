/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:16:07 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/13 23:44:18 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_VALID_MAP_UTILS_H
# define CHECK_VALID_MAP_UTILS_H

void	check_valid_char(t_map *map);
void	check_map_valid_shape(t_map *map);
void	check_map_sides(t_map *map, size_t count_column, \
						size_t count_row, char *line);
void	check_map_closed(t_map *map);
void	check_valid_map_element(t_map *map);
#endif
