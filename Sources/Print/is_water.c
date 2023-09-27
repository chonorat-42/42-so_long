/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_water.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:02:35 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 18:08:27 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	print_water_td(t_so_long *data, int *x, int *y)
{
	t_img	water_td;

	if (data->map[*y - 1][*x] != '1')
	{
		(*y)--;
		get_img(data, &water_td, "Assets/Water/Twater.xpm", 28);
		put_img_to_img(data, water_td, *x * 32, *y * 32);
		mlx_destroy_image(data->mlx, water_td.img_ptr);
		(*y)++;
	}
	if (data->map[*y + 1][*x] != '1')
	{
		(*y)++;
		get_img(data, &water_td, "Assets/Water/Dwater.xpm", 29);
		put_img_to_img(data, water_td, *x * 32, *y * 32);
		mlx_destroy_image(data->mlx, water_td.img_ptr);
		(*y)--;
	}
	return (1);
}

static int	print_water_l(t_so_long *data, int *x, int *y)
{
	t_img	water_l;

	(*x)--;
	get_img(data, &water_l, "Assets/Water/Lwater.xpm", 30);
	put_img_to_img(data, water_l, *x * 32, *y * 32);
	mlx_destroy_image(data->mlx, water_l.img_ptr);
	if (data->map[*y - 1][*x + 1] != '1')
	{
		(*y)--;
		get_img(data, &water_l, "Assets/Water/LAwater.xpm", 31);
		put_img_to_img(data, water_l, *x * 32, *y * 32);
		mlx_destroy_image(data->mlx, water_l.img_ptr);
		(*y)++;
	}
	(*x)++;
	return (1);
}

static int	print_water_r(t_so_long *data, int *x, int *y)
{
	t_img	water_r;

	(*x)++;
	get_img(data, &water_r, "Assets/Water/Rwater.xpm", 32);
	put_img_to_img(data, water_r, *x * 32, *y * 32);
	mlx_destroy_image(data->mlx, water_r.img_ptr);
	if (data->map[*y - 1][*x - 1] != '1')
	{
		(*y)--;
		get_img(data, &water_r, "Assets/Water/RAwater.xpm", 33);
		put_img_to_img(data, water_r, *x * 32, *y * 32);
		mlx_destroy_image(data->mlx, water_r.img_ptr);
		(*y)++;
	}
	(*x)--;
	return (1);
}

int	is_water(t_so_long *data, int x, int y)
{
	t_img	water;

	if (y == 0 || y == data->map_height - 1)
		return (0);
	if (x == 0 || x == data->map_width - 1)
		return (0);
	get_img(data, &water, "Assets/Water/Water.xpm", 27);
	put_img_to_img(data, water, x * 32, y * 32);
	mlx_destroy_image(data->mlx, water.img_ptr);
	if (data->map[y - 1][x] != '1' || data->map[y + 1][x] != '1')
		print_water_td(data, &x, &y);
	if (data->map[y][x - 1] != '1')
		print_water_l(data, &x, &y);
	if (data->map[y][x + 1] != '1')
		print_water_r(data, &x, &y);
	return (1);
}
