/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:30:59 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/11 16:44:45 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*load_map(char *file_path)
{
	int		fd;
	char	*str;
	char	*line;
	char	*tmp;


	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit(1);
	str = ft_strdup("");
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_printf("%s", line);
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
	}
	return (str);
}
