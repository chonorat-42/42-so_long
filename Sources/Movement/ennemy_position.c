/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:25:42 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 18:15:39 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ennemy_position(t_so_long *data)
{
	t_ennemy_list	*temp;

	temp = data->ennemy;
	while (temp)
	{
		if ((temp->last_pos[0] == data->player_pos[0]
				&& temp->last_pos[1] == data->player_pos[1])
			|| (temp->x_pos[0] == data->player_pos[0]
				&& temp->x_pos[1] == data->player_pos[1]))
		{
			data->heart--;
			if (!data->heart)
				exit_message(data);
			data->map[data->player_pos[0]][data->player_pos[1]] = 'X';
			data->map[temp->last_pos[0]][temp->last_pos[1]] = '0';
			data->player_pos[0] = data->player_spawn[0];
			data->player_pos[1] = data->player_spawn[1];
			data->map[data->player_pos[0]][data->player_pos[1]] = 'P';
		}
		temp = temp->next;
	}
}
