/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:14:31 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 15:30:53 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	set_player_spawn(t_so_long *data)
{
	data->player_spawn[0] = data->player_pos[0];
	data->player_spawn[1] = data->player_pos[1];
}

int	mlx_window(t_so_long *data)
{
	int	x_res;
	int	y_res;

	x_res = data->map_width * 32;
	y_res = data->map_height * 32;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, x_res, y_res, "so_long");
	if (!data->win)
		return (0);
	set_player_spawn(data);
	mlx_hook(data->win, KEY_PRESS, 1L << 0, get_hook, data);
	mlx_hook(data->win, ON_DESTROY, 0L, exit_success, data);
	print_assets(data);
	mlx_loop(data->mlx);
	return (1);
}
