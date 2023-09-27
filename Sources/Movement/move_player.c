/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:33:58 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 17:27:22 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	go_up(t_so_long *d)
{
	if (d->map[d->player_pos[0] - 1][d->player_pos[1]] != '1')
	{
		if (d->collectible
			&& d->map[d->player_pos[0] - 1][d->player_pos[1]] == 'E')
			return ;
		else if (d->map[d->player_pos[0] - 1][d->player_pos[1]] == 'C')
			d->collectible--;
		if (d->map[d->player_pos[0]][d->player_pos[1]] != 'X')
			d->map[d->player_pos[0]][d->player_pos[1]] = '0';
		d->player_pos[0]--;
		d->map[d->player_pos[0]][d->player_pos[1]] = 'P';
		d->move_count++;
	}
}

static void	go_down(t_so_long *d)
{
	if (d->map[d->player_pos[0] + 1][d->player_pos[1]] != '1')
	{
		if (d->collectible
			&& d->map[d->player_pos[0] + 1][d->player_pos[1]] == 'E')
			return ;
		else if (d->map[d->player_pos[0] + 1][d->player_pos[1]] == 'C')
			d->collectible--;
		if (d->map[d->player_pos[0]][d->player_pos[1]] != 'X')
			d->map[d->player_pos[0]][d->player_pos[1]] = '0';
		d->player_pos[0]++;
		d->map[d->player_pos[0]][d->player_pos[1]] = 'P';
		d->move_count++;
	}
}

static void	go_left(t_so_long *d)
{
	if (d->map[d->player_pos[0]][d->player_pos[1] - 1] != '1')
	{
		if (d->collectible
			&& d->map[d->player_pos[0]][d->player_pos[1] - 1] == 'E')
		{
			d->player_dir = -1;
			return ;
		}
		else if (d->map[d->player_pos[0]][d->player_pos[1] - 1] == 'C')
			d->collectible--;
		if (d->map[d->player_pos[0]][d->player_pos[1]] != 'X')
			d->map[d->player_pos[0]][d->player_pos[1]] = '0';
		d->player_pos[1]--;
		d->map[d->player_pos[0]][d->player_pos[1]] = 'P';
		d->move_count++;
	}
	d->player_dir = -1;
}

static void	go_right(t_so_long *d)
{
	if (d->map[d->player_pos[0]][d->player_pos[1] + 1] != '1')
	{
		if (d->collectible
			&& d->map[d->player_pos[0]][d->player_pos[1] + 1] == 'E')
		{
			d->player_dir = 1;
			return ;
		}
		else if (d->map[d->player_pos[0]][d->player_pos[1] + 1] == 'C')
			d->collectible--;
		if (d->map[d->player_pos[0]][d->player_pos[1]] != 'X')
			d->map[d->player_pos[0]][d->player_pos[1]] = '0';
		d->player_pos[1]++;
		d->map[d->player_pos[0]][d->player_pos[1]] = 'P';
		d->move_count++;
	}
	d->player_dir = 1;
}

void	move_player(int keycode, t_so_long *data)
{
	if (data->player_pos[0] != data->player_spawn[0]
		|| data->player_pos[1] != data->player_spawn[1])
		ennemy_movement(data);
	if (keycode == 119)
		go_up(data);
	else if (keycode == 115)
		go_down(data);
	else if (keycode == 97)
		go_left(data);
	else if (keycode == 100)
		go_right(data);
	if (!data->collectible && data->player_pos[0] == data->exit_pos[0]
		&& data->player_pos[1] == data->exit_pos[1])
		exit_message(data);
	ennemy_position(data);
	print_assets(data);
}
