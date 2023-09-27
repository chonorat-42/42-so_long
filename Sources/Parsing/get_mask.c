/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mask.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:01:54 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 14:48:21 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	prepare_mask(t_so_long *data)
{
	int	index;
	int	index_j;

	index = 0;
	while (data->map[index])
	{
		index_j = 0;
		while (data->map[index][index_j])
		{
			if (data->map[index][index_j] == '1')
				data->map_mask[index][index_j] = 'X';
			else if (data->map[index][index_j] == 'P')
				data->map_mask[index][index_j] = 'P';
			else if (data->map[index][index_j] == 'C')
				data->map_mask[index][index_j] = 'C';
			else if (data->map[index][index_j] == 'E')
				data->map_mask[index][index_j] = 'E';
			else if (data->map[index][index_j] == 'X')
				data->map_mask[index][index_j] = 'U';
			else
				data->map_mask[index][index_j] = '0';
			index_j++;
		}
		index++;
	}
}

int	get_mask(t_so_long *data)
{
	int		index;

	data->map_mask = malloc((data->map_height + 1) * sizeof(char *));
	if (!data->map_mask)
		return (0);
	index = 0;
	while (index < data->map_height)
	{
		data->map_mask[index] = malloc((data->map_width + 1) * sizeof(char));
		if (!data->map_mask[index])
			return (0);
		data->map_mask[index++][data->map_width] = '\0';
	}
	data->map_mask[index] = NULL;
	prepare_mask(data);
	return (1);
}
