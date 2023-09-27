/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:22:48 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 15:58:34 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	get_img(t_so_long *d, t_img *img, char *path, int error)
{
	*img = new_file_img(path, d);
	if (!img->img_ptr)
		return (show_error(*d, "XPM_ERROR"), exit_program(d, error));
	return (1);
}

int	top_walls(t_so_long *data, int i)
{
	int		j;
	t_img	top_w;

	j = 0;
	if (i == 0)
	{
		get_img(data, &top_w, "Assets/Walls/Langle.xpm", 15);
		put_img_to_img(data, top_w, 0, 0);
		mlx_destroy_image(data->mlx, top_w.img_ptr);
		j++;
	}
	get_img(data, &top_w, "Assets/Walls/Top.xpm", 16);
	while (i == 0)
	{
		while (data->map[i][j])
		{
			put_img_to_img(data, top_w, j * 32, 0);
			j++;
		}
		(i)++;
	}
	mlx_destroy_image(data->mlx, top_w.img_ptr);
	return (1);
}

int	down_walls(t_so_long *data, int i)
{
	int		j;
	t_img	down_w;

	j = 1;
	get_img(data, &down_w, "Assets/Walls/Down.xpm", 22);
	while (data->map[i][j])
	{
		put_img_to_img(data, down_w, j * 32, i * 32);
		j++;
	}
	mlx_destroy_image(data->mlx, down_w.img_ptr);
	j--;
	get_img(data, &down_w, "Assets/Walls/DRangle.xpm", 23);
	put_img_to_img(data, down_w, j * 32, i * 32);
	mlx_destroy_image(data->mlx, down_w.img_ptr);
	return (1);
}

int	left_walls(t_so_long *data, int i)
{
	t_img	left_w;

	if (i == 0)
	{
		get_img(data, &left_w, "Assets/Walls/Langle.xpm", 17);
		put_img_to_img(data, left_w, 0, 0);
		mlx_destroy_image(data->mlx, left_w.img_ptr);
		i++;
	}
	get_img(data, &left_w, "Assets/Walls/Left.xpm", 18);
	while (data->map[i])
	{
		put_img_to_img(data, left_w, 0, i * 32);
		i++;
	}
	mlx_destroy_image(data->mlx, left_w.img_ptr);
	i--;
	get_img(data, &left_w, "Assets/Walls/DLangle.xpm", 19);
	put_img_to_img(data, left_w, 0, i * 32);
	mlx_destroy_image(data->mlx, left_w.img_ptr);
	return (1);
}

int	right_walls(t_so_long *d, int i, int j)
{
	t_img	right_w;

	if (i == 0)
	{
		while (d->map[i][j + 1])
			j++;
		get_img(d, &right_w, "Assets/Walls/Rangle.xpm", 20);
		put_img_to_img(d, right_w, j * 32, 0);
		mlx_destroy_image(d->mlx, right_w.img_ptr);
		i++;
	}
	get_img(d, &right_w, "Assets/Walls/Right.xpm", 21);
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j + 1])
			j++;
		put_img_to_img(d, right_w, j * 32, i * 32);
		i++;
	}
	mlx_destroy_image(d->mlx, right_w.img_ptr);
	return (1);
}
