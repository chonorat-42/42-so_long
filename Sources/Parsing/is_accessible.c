/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accessible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:33:09 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 15:00:57 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	get_ennemy_count(t_so_long *data)
{
	int	index;
	int	index_j;

	index = 0;
	index_j = 0;
	data->ennemy_count = 0;
	while (data->map[index])
	{
		index_j = 0;
		while (data->map[index][index_j])
		{
			if (data->map[index][index_j] == 'X')
				data->ennemy_count++;
			index_j++;
		}
		index++;
	}
	return (data->ennemy_count);
}

static void	get_ennemy_pos(t_so_long *data)
{
	int				index;
	int				index_j;
	t_ennemy_list	*temp;

	index = 0;
	init_ennemy(data);
	temp = data->ennemy;
	while (data->map[index] && temp)
	{
		index_j = 0;
		while (data->map[index][index_j] && temp)
		{
			if (data->map[index][index_j] == 'X')
			{
				temp->x_pos[0] = index;
				temp->x_pos[1] = index_j;
				temp = temp->next;
			}
			index_j++;
		}
		index++;
	}
}

static void	get_player_pos(t_so_long *data)
{
	int	index;
	int	index_j;

	index = 0;
	while (data->map[index])
	{
		index_j = 0;
		while (data->map[index][index_j])
		{
			if (data->map[index][index_j] == 'P')
			{
				data->player_pos[0] = index;
				data->player_pos[1] = index_j;
			}
			index_j++;
		}
		index++;
	}
}

static int	exit_is_accessible(t_so_long *data)
{
	if (data->exit_pos[0] != -1 && data->exit_pos[1] != -1)
	{
		if (data->map_mask[data->exit_pos[0]][data->exit_pos[1] - 1] == '1')
			return (1);
		if (data->map_mask[data->exit_pos[0]][data->exit_pos[1] + 1] == '1')
			return (1);
		if (data->map_mask[data->exit_pos[0] - 1][data->exit_pos[1]] == '1')
			return (1);
		if (data->map_mask[data->exit_pos[0] + 1][data->exit_pos[1]] == '1')
			return (1);
	}
	return (0);
}

int	is_accessible(t_so_long *data)
{
	int	tmp_collectible;
	int	tmp_exit;

	tmp_collectible = data->collectible;
	tmp_exit = data->exit;
	get_mask(data);
	if (!data->map_mask)
		return (0);
	get_player_pos(data);
	accessible_path(data, data->player_pos[0], data->player_pos[1]);
	if (data->collectible || !exit_is_accessible(data))
		return (0);
	data->collectible = tmp_collectible;
	data->exit = tmp_exit;
	if (get_ennemy_count(data))
		get_ennemy_pos(data);
	return (1);
}
