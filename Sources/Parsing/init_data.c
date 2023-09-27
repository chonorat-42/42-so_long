/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:22:03 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 15:00:39 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	init_ennemy(t_so_long *data)
{
	int				index;
	t_ennemy_list	*temp;

	data->ennemy = new_ennemy();
	if (!data->ennemy)
		return (0);
	index = 1;
	while (index < data->ennemy_count)
	{
		temp = new_ennemy();
		add_back(data, temp);
		index++;
	}
	return (1);
}

void	init_data(t_so_long *data)
{
	data->map = NULL;
	data->map_mask = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->player = 0;
	data->player_dir = 1;
	data->player_spawn[0] = -1;
	data->player_spawn[1] = -1;
	data->player_pos[0] = -1;
	data->player_pos[1] = -1;
	data->collectible = 0;
	data->exit = 0;
	data->exit_pos[0] = -1;
	data->exit_pos[1] = -1;
	data->ennemy_count = 0;
	data->ennemy = NULL;
	data->move_count = 0;
	data->heart = 9;
	data->move_string = NULL;
	data->mlx = NULL;
	data->win = NULL;
}
