/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:25:57 by hkumagai          #+#    #+#             */
/*   Updated: 2022/10/11 17:34:13 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/gnl/include/get_next_line_bonus.h"
# include "../lib/libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../include/load_map.h"
# include "../include/check_valid_map.h"

typedef struct s_mlx_info
{
	void	*mlx;
	void	*win;
}	t_mlx_info;

#endif
