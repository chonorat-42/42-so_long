/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:01:43 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 14:44:57 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	new_img(t_so_long *data)
{
	data->base_img.img_ptr = mlx_new_image(data->mlx,
			data->map_width * 32, data->map_height * 32);
	data->base_img.addr = mlx_get_data_addr(data->base_img.img_ptr,
			&(data->base_img.bpp), &(data->base_img.line_len),
			&(data->base_img.endian));
	data->base_img.w = data->map_width * 32;
	data->base_img.h = data->map_height * 32;
}

t_img	new_file_img(char *path, t_so_long *data)
{
	t_img	image;

	image.img_ptr = mlx_xpm_file_to_image(data->mlx, path, &image.w, &image.h);
	if (!image.img_ptr)
		return (image);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
				&(image.line_len), &(image.endian));
	return (image);
}

static void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

static unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}

void	put_img_to_img(t_so_long *data, t_img src, int x, int y)
{
	int	index;
	int	index_j;

	index = 0;
	while (index < src.w)
	{
		index_j = 0;
		while (index_j < src.h)
		{
			put_pixel_img(data->base_img, x + index, y + index_j,
				get_pixel_img(src, index, index_j));
			index_j++;
		}
		index++;
	}
}
