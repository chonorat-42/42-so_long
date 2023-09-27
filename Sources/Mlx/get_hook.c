/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:17:49 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 13:41:33 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	exit_program(t_so_long *data, int exit_code)
{
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit(exit_code);
	return (1);
}

int	exit_success(t_so_long *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit(EXIT_SUCCESS);
	return (1);
}

int	get_hook(int keycode, t_so_long *data)
{
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		move_player(keycode, data);
	else if (keycode == 65307)
		exit_success(data);
	return (1);
}
