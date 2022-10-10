/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:09:54 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/10 17:34:30 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

char	*ft_read_data(int fd, char *save)
{
	ssize_t	read_byte;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (size_t)(BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_byte = 1;
	while (ft_strchr_gnl(save, '\n') == NULL)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == 0 || read_byte == -1)
			break ;
		buf[read_byte] = '\0';
		save = ft_strjoin_gnl(save, buf);
		if (save == NULL)
			break ;
	}
	free(buf);
	if (read_byte == -1)
		return (NULL);
	return (save);
}

char	*get_line(char *save)
{
	char	*line;
	int		i;

	if (!save || *save == '\0')
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char *) * (i + (save[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_remain_data(char *save)
{
	ssize_t	i;
	ssize_t	ri;
	char	*tmp;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen_gnl(save) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	ri = 0;
	while (save[i + ri])
	{
		tmp[ri] = save[i + ri];
		ri++;
	}
	tmp[ri] = '\0';
	free(save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save[256];
	char		*line;

	if (fd < 0 || fd > 256)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read_data(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_line(save[fd]);
	save[fd] = get_remain_data(save[fd]);
	return (line);
}
