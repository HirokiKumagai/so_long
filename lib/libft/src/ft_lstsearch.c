/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 06:41:33 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/21 15:06:27 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstsearch(t_list **lst, size_t num)
{
	size_t	index;
	size_t	size;
	t_list	*tmp;

	index = 0;
	size = ft_lstsize(*lst) - 1;
	tmp = *lst;
	if (num > size)
		return (NULL);
	while (index < num)
	{
		tmp = tmp->next;
		index++;
	}
	(void)index;
	return (tmp);
}
