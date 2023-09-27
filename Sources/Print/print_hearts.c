/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hearts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 01:26:50 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 16:04:24 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	print_high(t_so_long *data)
{
	t_img	hearts;

	if (data->heart == 8)
	{
		hearts = new_file_img("Assets/Hearts/8Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 56));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	else if (data->heart == 7)
	{
		hearts = new_file_img("Assets/Hearts/7Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 57));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	return (1);
}

static int	print_midhigh(t_so_long *data)
{
	t_img	hearts;

	if (data->heart == 6)
	{
		hearts = new_file_img("Assets/Hearts/6Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 58));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	else if (data->heart == 5)
	{
		hearts = new_file_img("Assets/Hearts/5Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 59));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	return (1);
}

static int	print_mid(t_so_long *data)
{
	t_img	hearts;

	if (data->heart == 4)
	{
		hearts = new_file_img("Assets/Hearts/4Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 60));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	else if (data->heart == 3)
	{
		hearts = new_file_img("Assets/Hearts/3Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 61));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	return (1);
}

static int	print_low(t_so_long *data)
{
	t_img	hearts;

	if (data->heart == 2)
	{
		hearts = new_file_img("Assets/Hearts/2Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 62));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	else if (data->heart == 1)
	{
		hearts = new_file_img("Assets/Hearts/1Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 63));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	return (1);
}

int	print_hearts(t_so_long *data)
{
	t_img	hearts;

	if (data->heart == 9)
	{
		hearts = new_file_img("Assets/Hearts/9Hearts.xpm", data);
		if (!hearts.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 55));
		put_img_to_img(data, hearts, ((data->map_width * 32) / 2) - 80,
			((data->map_height - 1) * 32) + 8);
		mlx_destroy_image(data->mlx, hearts.img_ptr);
	}
	else if (data->heart >= 7)
		print_high(data);
	else if (data->heart >= 5)
		print_midhigh(data);
	else if (data->heart >= 3)
		print_mid(data);
	else if (data->heart >= 1)
		print_low(data);
	return (1);
}
