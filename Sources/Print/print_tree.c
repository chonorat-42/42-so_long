/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:11:58 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 16:03:16 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	print_top(t_so_long *data, int x, int y)
{
	t_img	top;

	top = new_file_img("Assets/Tree/LTTree.xpm", data);
	if (!top.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 52));
	put_img_to_img(data, top, (x - 1) * 32, (y - 2) * 32);
	mlx_destroy_image(data->mlx, top.img_ptr);
	top = new_file_img("Assets/Tree/MTTree.xpm", data);
	if (!top.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 53));
	put_img_to_img(data, top, x * 32, (y - 2) * 32);
	mlx_destroy_image(data->mlx, top.img_ptr);
	top = new_file_img("Assets/Tree/RTTree.xpm", data);
	if (!top.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 54));
	put_img_to_img(data, top, (x + 1) * 32, (y - 2) * 32);
	mlx_destroy_image(data->mlx, top.img_ptr);
	return (1);
}

static int	print_middle(t_so_long *data, int x, int y)
{
	t_img	middle;

	middle = new_file_img("Assets/Tree/LMTree.xpm", data);
	if (!middle.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 49));
	put_img_to_img(data, middle, (x - 1) * 32, (y - 1) * 32);
	mlx_destroy_image(data->mlx, middle.img_ptr);
	middle = new_file_img("Assets/Tree/MMTree.xpm", data);
	if (!middle.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 50));
	put_img_to_img(data, middle, x * 32, (y - 1) * 32);
	mlx_destroy_image(data->mlx, middle.img_ptr);
	middle = new_file_img("Assets/Tree/RMTree.xpm", data);
	if (!middle.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 51));
	put_img_to_img(data, middle, (x + 1) * 32, (y - 1) * 32);
	mlx_destroy_image(data->mlx, middle.img_ptr);
	return (1);
}

static int	print_bottom(t_so_long *data, int x, int y)
{
	t_img	bottom;

	bottom = new_file_img("Assets/Tree/LBTree.xpm", data);
	if (!bottom.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 46));
	put_img_to_img(data, bottom, (x - 1) * 32, y * 32);
	mlx_destroy_image(data->mlx, bottom.img_ptr);
	bottom = new_file_img("Assets/Tree/MBTree.xpm", data);
	if (!bottom.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 47));
	put_img_to_img(data, bottom, x * 32, y * 32);
	mlx_destroy_image(data->mlx, bottom.img_ptr);
	bottom = new_file_img("Assets/Tree/RBTree.xpm", data);
	if (!bottom.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 48));
	put_img_to_img(data, bottom, (x + 1) * 32, y * 32);
	mlx_destroy_image(data->mlx, bottom.img_ptr);
	return (1);
}

int	print_tree(t_so_long *data)
{
	int	y;
	int	x;

	y = 1;
	while (data->map[y])
	{
		x = 1;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1' && data->map[y][x + 1] != '1'
				&& data->map[y][x - 1] != '1')
			{
				if (data->map[y + 1][x] != '1' && data->map[y - 1][x] != '1')
				{
					print_middle(data, x, y);
					print_top(data, x, y);
					print_bottom(data, x, y);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}
