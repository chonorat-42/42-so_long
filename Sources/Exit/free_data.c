/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:53:36 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 12:51:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	free_list(t_so_long *data)
{
	t_ennemy_list	*temp;
	t_ennemy_list	*freed;

	freed = data->ennemy;
	while (freed)
	{
		temp = freed->next;
		free(freed);
		freed = temp;
	}
}

void	free_data(t_so_long *data)
{
	int	index;

	index = 0;
	if (data->map)
	{
		while (data->map[index])
			free(data->map[index++]);
		free(data->map);
	}
	if (data->map_mask)
	{
		index = 0;
		while (data->map_mask[index])
			free(data->map_mask[index++]);
		free(data->map_mask);
	}
	if (data->ennemy)
		free_list(data);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
