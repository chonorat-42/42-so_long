/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:25:22 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 17:42:20 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	check_size(t_so_long *data)
{
	int	index;
	int	index_j;

	index = 0;
	index_j = 0;
	while (data->map[index])
	{
		while (data->map[index][index_j])
			index_j++;
		if (data->map_width && data->map_width != index_j)
			return (0);
		data->map_width = index_j;
		index_j = 0;
		index++;
	}
	if (data->map_height < 3 || data->map_width < 3)
		return (0);
	return (1);
}

static int	anti_immigration(t_so_long data)
{
	int	index;

	index = 0;
	while (data.map[0][index])
	{
		if (data.map[0][index++] != '1')
			return (0);
	}
	index = 0;
	while (data.map[index])
	{
		if (data.map[index][0] != '1')
			return (0);
		if (data.map[index][data.map_width - 1] != '1')
			return (0);
		index++;
	}
	index = 0;
	while (data.map[data.map_height - 1][index])
	{
		if (data.map[data.map_height - 1][index++] != '1')
			return (0);
	}
	return (1);
}

static int	check_elements(t_so_long *data)
{
	int	index;
	int	index_j;

	index = 1;
	index_j = 0;
	while (data->map[index])
	{
		while (data->map[index][index_j])
		{
			if (data->map[index][index_j] == 'C')
				data->collectible++;
			if (data->map[index][index_j] == 'P')
				data->player++;
			if (data->map[index][index_j] == 'E')
				data->exit++;
			if (data->map[index][index_j] == 'X')
				data->ennemy_count++;
			index_j++;
		}
		index_j = 0;
		index++;
	}
	if (data->player != 1 || data->exit != 1 || data->collectible == 0)
		return (0);
	return (1);
}

static int	valid_map(t_so_long data)
{
	int	index;
	int	index_j;

	index = 0;
	while (data.map[index])
	{
		index_j = 0;
		while (data.map[index][index_j])
		{
			if (data.map[index][index_j] != '0')
				if (data.map[index][index_j] != '1')
					if (data.map[index][index_j] != 'P')
						if (data.map[index][index_j] != 'C')
							if (data.map[index][index_j] != 'E')
								if (data.map[index][index_j] != 'X')
									return (0);
			index_j++;
		}
		index++;
	}
	return (1);
}

int	check_map(t_so_long *data)
{
	if (!check_size(data))
		return (show_error(*data, "SIZE_ERROR"), 8);
	if (!valid_map(*data))
		return (show_error(*data, "INVALID_MAP"), 9);
	if (!anti_immigration(*data))
		return (show_error(*data, "BORDER_BREACHED"), 10);
	if (!check_elements(data))
		return (show_error(*data, "ELEMENT_ERROR"), 11);
	if (!is_accessible(data))
		return (show_error(*data, "CANNOT_COMPLETE"), 12);
	return (0);
}
