/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:25:58 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 18:08:02 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	print_walls(t_so_long *data)
{
	top_walls(data, 0);
	left_walls(data, 0);
	right_walls(data, 0, 0);
	down_walls(data, data->map_height - 1);
	return (1);
}

static int	print_background(t_so_long *data)
{
	int		i;
	int		j;
	t_img	back;

	back = new_file_img("Assets/Grass.xpm", data);
	if (!back.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 14));
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_img_to_img(data, back, j * 32, i * 32);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, back.img_ptr);
	return (1);
}

static int	print_water(t_so_long *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if ((i - 1) >= 0 && (j - 1) >= 0)
			{
				if (data->map[i][j] == '1' && !is_tree(data, j, i))
					is_water(data, j, i);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	print_collectibles(t_so_long *data)
{
	int		index;
	int		index_j;
	t_img	collec;

	collec = new_file_img("Assets/Fish.xpm", data);
	if (!collec.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 24));
	index = 0;
	while (data->map[index])
	{
		index_j = 0;
		while (data->map[index][index_j])
		{
			if (data->map[index][index_j] == 'C')
				put_img_to_img(data, collec, index_j * 32, index * 32);
			index_j++;
		}
		index++;
	}
	mlx_destroy_image(data->mlx, collec.img_ptr);
	return (1);
}

void	print_assets(t_so_long *data)
{
	new_img(data);
	print_background(data);
	print_walls(data);
	print_collectibles(data);
	print_water(data);
	print_ennemy(data);
	print_player(data);
	print_exit(data);
	print_tree(data);
	print_hearts(data);
	mlx_put_image_to_window(data->mlx, data->win, data->base_img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->base_img.img_ptr);
	print_move(data);
}
