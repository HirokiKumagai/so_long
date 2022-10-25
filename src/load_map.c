/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:30:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/25 14:34:07 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		ft_exit_and_print_error("ERROR!!! no memory...");
	map->valid_flag = false;
	map->count_column = 0;
	map->count_row = 0;
	map->count_exit = 0;
	map->count_collection = 0;
	map->count_player = 0;
	return (map);
}

static void	load_map_element(t_map *map, char *file_path)
{
	int		fd;
	char	*str;
	char	*line;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		ft_exit_and_print_error("ERROR!!! can't open file.");
	str = ft_strdup("");
	if (str == NULL)
		ft_exit_and_print_error("ERROR!!! no memory...");
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = str;
		str = ft_strjoin(str, line);
		map->count_column++;
		free(tmp);
		free(line);
	}
	map->map_element = str;
	return ;
}

static void	count_map_row(t_map *map)
{
	char	*line;

	line = map->map_element;
	while (*line != '\n')
	{
		line++;
		map->count_row++;
	}
	return ;
}

static void	count_map_element(t_map *map)
{
	char	*ele;

	ele = map->map_element;
	while (*(map->map_element) != '\0')
	{
		if (*(map->map_element) == 'E')
			map->count_exit++;
		if (*(map->map_element) == 'C')
			map->count_collection++;
		if (*(map->map_element) == 'P')
			map->count_player++;
		map->map_element++;
	}
	map->map_element = ele;
	return ;
}

t_map	*load_map(char *file_path)
{
	t_map	*map;

	map = init_map();
	load_map_element(map, file_path);
	count_map_row(map);
	count_map_element(map);
	return (map);
}
