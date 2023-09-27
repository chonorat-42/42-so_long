/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 02:04:25 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 16:02:43 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	print_lexit(t_so_long *data, int index, int index_j)
{
	t_img	lexit;

	lexit = new_file_img("Assets/Exit/LExit.xpm", data);
	if (!lexit.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 44));
	put_img_to_img(data, lexit, index_j * 32, index * 32);
	mlx_destroy_image(data->mlx, lexit.img_ptr);
	return (1);
}

static int	print_rexit(t_so_long *data, int index, int index_j)
{
	t_img	rexit;

	rexit = new_file_img("Assets/Exit/RExit.xpm", data);
	if (!rexit.img_ptr)
		return (show_error(*data, "XPM_ERROR"), exit_program(data, 45));
	put_img_to_img(data, rexit, index_j * 32, index * 32);
	mlx_destroy_image(data->mlx, rexit.img_ptr);
	return (1);
}

int	print_exit(t_so_long *data)
{
	int	index;
	int	index_j;

	index = 1;
	while (index < data->map_height - 1)
	{
		index_j = 1;
		while (index_j < data->map_width - 1)
		{
			if (data->map[index][index_j] == 'E')
			{
				if (index_j > data->player_pos[1])
					print_lexit(data, index, index_j);
				else
					print_rexit(data, index, index_j);
			}
			index_j++;
		}
		index++;
	}
	return (1);
}
