/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:30:13 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/14 10:52:36 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_H
# define LOAD_MAP_H

typedef struct s_map_info
{
	void	*mlx;
	void	*win;
	char	*map_element;
	char	**map;
	size_t	count_column;
	size_t	count_row;
	size_t	count_exit;
	size_t	count_player;
	size_t	count_collection;
}	t_map;

t_map	*load_map(char *file_path);
#endif
