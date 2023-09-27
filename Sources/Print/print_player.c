/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:10:26 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 15:42:20 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	player_altl(t_so_long *data, int index, int index_j)
{
	t_img	altl;

	if (data->map[index][index_j - 1] == 'X')
	{
		altl = new_file_img("Assets/Player/PlayerAlt2L.xpm", data);
		if (!altl.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 38));
		put_img_to_img(data, altl, index_j * 32, index * 32);
		mlx_destroy_image(data->mlx, altl.img_ptr);
	}
	else
	{
		altl = new_file_img("Assets/Player/PlayerAlt1L.xpm", data);
		if (!altl.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 39));
		put_img_to_img(data, altl, index_j * 32, index * 32);
		mlx_destroy_image(data->mlx, altl.img_ptr);
	}
	return (1);
}

static int	player_altr(t_so_long *data, int index, int index_j)
{
	t_img	altr;

	if (data->map[index][index_j + 1] == 'X')
	{
		altr = new_file_img("Assets/Player/PlayerAlt2R.xpm", data);
		if (!altr.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 41));
		put_img_to_img(data, altr, index_j * 32, index * 32);
		mlx_destroy_image(data->mlx, altr.img_ptr);
	}
	else
	{
		altr = new_file_img("Assets/Player/PlayerAlt1R.xpm", data);
		if (!altr.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 42));
		put_img_to_img(data, altr, index_j * 32, index * 32);
		mlx_destroy_image(data->mlx, altr.img_ptr);
	}
	return (1);
}

static int	player_left(t_so_long *data, int index, int index_j)
{
	t_img	left;

	if ((index_j - 2) >= 0)
	{
		if (data->map[index][index_j - 2] == 'X'
			|| data->map[index][index_j - 1] == 'X')
		{
			player_altl(data, index, index_j);
			return (1);
		}
	}
	left = new_file_img("Assets/Player/PlayerL.xpm", data);
	if (!left.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 40));
	put_img_to_img(data, left, index_j * 32, index * 32);
	mlx_destroy_image(data->mlx, left.img_ptr);
	return (1);
}

static int	player_right(t_so_long *data, int index, int index_j)
{
	t_img	right;

	if ((index_j + 2) >= 0)
	{
		if (data->map[index][index_j + 2] == 'X'
			|| data->map[index][index_j + 1] == 'X')
		{
			player_altr(data, index, index_j);
			return (1);
		}
	}
	right = new_file_img("Assets/Player/PlayerR.xpm", data);
	if (!right.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 43));
	put_img_to_img(data, right, index_j * 32, index * 32);
	mlx_destroy_image(data->mlx, right.img_ptr);
	return (1);
}

int	print_player(t_so_long *data)
{
	int	index;
	int	index_j;

	index = 1;
	while (index < data->map_height - 1)
	{
		index_j = 1;
		while (index_j < data->map_width - 1)
		{
			if (data->map[index][index_j] == 'P')
			{
				if (data->player_dir == -1)
					player_left(data, index, index_j);
				else
					player_right(data, index, index_j);
			}
			index_j++;
		}
		index++;
	}
	return (1);
}
