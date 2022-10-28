/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:30:13 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/28 12:02:11 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_H
# define LOAD_MAP_H

t_map	*load_map(char *file_path);
void	fill_in_map(t_game_data *data, t_map *map);
void	search_player_and_exit(t_game_data *data, t_map *map);
#endif
