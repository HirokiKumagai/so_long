/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:26:42 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/28 11:39:25 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*check_valid_map(t_game_data *data, t_map *map)
{
	if (!is_valid_char(map) || !is_valid_rectangle(map) || \
		!is_map_closed(map) || !is_valid_map_element(map) || \
		!is_valid_map_size(data))
		exit(EXIT_FAILURE);
	fill_in_map(data, map);
	search_player_and_exit(data, map);
	if (!is_valid_path(data))
		exit(EXIT_FAILURE);
	return (map);
}
