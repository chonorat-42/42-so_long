/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ennemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:37:09 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 16:01:31 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	print_ennemyl(t_so_long *data, t_ennemy_list *temp)
{
	t_img	ennemy_l;

	if (temp->last_pos[1] - data->player_pos[1] == 1)
	{
		ennemy_l = new_file_img("Assets/Ennemy/BarkDogL.xpm", data);
		if (!ennemy_l.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 34));
		put_img_to_img(data, ennemy_l, temp->x_pos[1] * 32,
			temp->x_pos[0] * 32);
		mlx_destroy_image(data->mlx, ennemy_l.img_ptr);
	}
	else
	{
		ennemy_l = new_file_img("Assets/Ennemy/RunDogL.xpm", data);
		if (!ennemy_l.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 35));
		put_img_to_img(data, ennemy_l, temp->x_pos[1] * 32,
			temp->x_pos[0] * 32);
		mlx_destroy_image(data->mlx, ennemy_l.img_ptr);
	}
	return (1);
}

static int	print_ennemyr(t_so_long *data, t_ennemy_list *temp)
{
	t_img	ennemy_r;

	if (data->player_pos[1] - temp->last_pos[1] == 1)
	{
		ennemy_r = new_file_img("Assets/Ennemy/BarkDogR.xpm", data);
		if (!ennemy_r.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 36));
		put_img_to_img(data, ennemy_r, temp->x_pos[1] * 32,
			temp->x_pos[0] * 32);
		mlx_destroy_image(data->mlx, ennemy_r.img_ptr);
	}
	else
	{
		ennemy_r = new_file_img("Assets/Ennemy/RunDogR.xpm", data);
		if (!ennemy_r.img_ptr)
			return (show_error(*data, "XPM_ERROR"), exit_program(data, 37));
		put_img_to_img(data, ennemy_r, temp->x_pos[1] * 32,
			temp->x_pos[0] * 32);
		mlx_destroy_image(data->mlx, ennemy_r.img_ptr);
	}
	return (1);
}

int	print_ennemy(t_so_long *data)
{
	t_ennemy_list	*temp;

	temp = data->ennemy;
	while (temp)
	{
		if (temp->dir == -1)
			print_ennemyl(data, temp);
		else if (temp->dir == 1)
			print_ennemyr(data, temp);
		temp = temp->next;
	}
	return (1);
}
