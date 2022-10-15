/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:25:06 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/15 10:25:38 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_in_map(t_map *map)
{
	size_t	i;
	char	**lines;
	char	**tmp;

	map->map = (char **)malloc(sizeof(char *) * (map->count_column + 1));
	if (!map->map)
		exit(1);
	lines = ft_split(map->map_element, '\n');
	if (lines == NULL)
		exit(1);
	tmp = lines;
	i = 0;
	while (*lines != NULL)
	{
		map->map[i] = *lines;
		lines++;
		i++;
	}
	map->map[i] = NULL;
	free(tmp);
	return ;
}
