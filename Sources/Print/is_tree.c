/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:06:24 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 16:00:02 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	left_shadow(t_so_long *data, int x, int y)
{
	t_img	l_shadow;

	l_shadow = new_file_img("Assets/Tree/ShadowL.xpm", data);
	if (!l_shadow.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 25));
	put_img_to_img(data, l_shadow, (x - 1) * 32, y * 32);
	mlx_destroy_image(data->mlx, l_shadow.img_ptr);
	return (1);
}

static int	right_shadow(t_so_long *data, int x, int y)
{
	t_img	r_shadow;

	r_shadow = new_file_img("Assets/Tree/ShadowR.xpm", data);
	if (!r_shadow.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 26));
	put_img_to_img(data, r_shadow, (x + 1) * 32, y * 32);
	mlx_destroy_image(data->mlx, r_shadow.img_ptr);
	return (1);
}

int	is_tree(t_so_long *data, int x, int y)
{
	if (data->map[y][x + 1] != '1' && data->map[y][x - 1] != '1')
	{
		if (data->map[y + 1][x] != '1' && data->map[y - 1][x] != '1')
		{
			left_shadow(data, x, y);
			right_shadow(data, x, y);
			return (1);
		}
	}
	return (0);
}
