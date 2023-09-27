/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessible_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:42:58 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 14:47:22 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	accessible_path(t_so_long *data, int y, int x)
{
	if (data->map_mask[y][x] == 'X' || data->map_mask[y][x] == 'U')
		return ;
	if (data->map_mask[y][x] == '0' || data->map_mask[y][x] == 'C'
	|| data->map_mask[y][x] == 'E' || data->map_mask[y][x] == 'P')
	{
		if (data->map_mask[y][x] == 'C')
			data->collectible--;
		else if (data->map_mask[y][x] == 'E')
		{
			data->exit--;
			data->exit_pos[0] = y;
			data->exit_pos[1] = x;
			if (data->collectible)
				return ;
		}
		data->map_mask[y][x] = '1';
		accessible_path(data, y - 1, x);
		accessible_path(data, y + 1, x);
		accessible_path(data, y, x + 1);
		accessible_path(data, y, x - 1);
	}
}
