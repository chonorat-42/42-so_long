/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 01:29:05 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 13:52:50 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	left_move(t_so_long *data, t_ennemy_list **temp)
{
	if ((*temp)->x_pos[1] > data->player_pos[1] && (*temp)->move_switch == 0
		&& data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] - 1] != '1')
	{
		if (data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] - 1] != 'E'
			&& data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] - 1] != 'X'
			&& data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] - 1] != 'C')
		{
			data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1]--] = '0';
			data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1]] = 'X';
			(*temp)->move_switch = 1;
			(*temp)->dir = -1;
		}
	}
}

static void	right_move(t_so_long *data, t_ennemy_list **temp)
{
	if ((*temp)->x_pos[1] < data->player_pos[1] && (*temp)->move_switch == 0
		&& data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] + 1] != '1' &&
		data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] + 1] != '1')
	{
		if (data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] + 1] != 'E'
			&& data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] + 1] != 'X'
			&& data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1] + 1] != 'C')
		{
			data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1]++] = '0';
			data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1]] = 'X';
			(*temp)->move_switch = 1;
			(*temp)->dir = 1;
		}
	}
}

static void	up_move(t_so_long *data, t_ennemy_list **temp)
{
	if ((*temp)->x_pos[0] > data->player_pos[0] && (*temp)->move_switch == 0
		&& data->map[(*temp)->x_pos[0] - 1][(*temp)->x_pos[1]] != '1')
	{
		if (data->map[(*temp)->x_pos[0] - 1][(*temp)->x_pos[1]] != 'E'
			&& data->map[(*temp)->x_pos[0] - 1][(*temp)->x_pos[1]] != 'X'
			&& data->map[(*temp)->x_pos[0] - 1][(*temp)->x_pos[1]] != 'C')
		{
			data->map[(*temp)->x_pos[0]--][(*temp)->x_pos[1]] = '0';
			data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1]] = 'X';
			(*temp)->move_switch = 1;
		}
	}
}

static void	down_move(t_so_long *data, t_ennemy_list **temp)
{
	if ((*temp)->x_pos[0] < data->player_pos[0] && (*temp)->move_switch == 0
		&& data->map[(*temp)->x_pos[0] + 1][(*temp)->x_pos[1]] != '1')
	{
		if (data->map[(*temp)->x_pos[0] + 1][(*temp)->x_pos[1]] != 'E'
			&& data->map[(*temp)->x_pos[0] + 1][(*temp)->x_pos[1]] != 'X'
			&& data->map[(*temp)->x_pos[0] + 1][(*temp)->x_pos[1]] != 'C')
		{
			data->map[(*temp)->x_pos[0]++][(*temp)->x_pos[1]] = '0';
			data->map[(*temp)->x_pos[0]][(*temp)->x_pos[1]] = 'X';
			(*temp)->move_switch = 1;
		}
	}
}

void	ennemy_movement(t_so_long *data)
{
	t_ennemy_list	*temp;

	temp = data->ennemy;
	while (temp)
	{
		temp->last_pos[0] = temp->x_pos[0];
		temp->last_pos[1] = temp->x_pos[1];
		up_move(data, &temp);
		down_move(data, &temp);
		left_move(data, &temp);
		right_move(data, &temp);
		temp->move_switch = 0;
		temp = temp->next;
	}
}
