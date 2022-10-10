/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:09:52 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/10 17:35:02 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr_gnl(const char *src, int c)
{
	if (!src)
		return (NULL);
	while (*src != '\0' && *src != (char)c)
		src++;
	if (*src == (char)c)
		return ((char *)src);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dst;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup_gnl(s2));
	if (s2 == NULL)
		return (ft_strdup_gnl(s1));
	dst = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) \
			+ ft_strlen_gnl(s2) + 1));
	if (dst == NULL)
	{
		free(s1);
		return (NULL);
	}
	dst = ft_strlcat_gnl(dst, s1, s2);
	free(s1);
	return (dst);
}

char	*ft_strlcat_gnl(char *dst, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*p;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	p = (char *)malloc(sizeof(char *) * (ft_strlen_gnl(s1) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
