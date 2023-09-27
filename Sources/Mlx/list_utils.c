/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:30:02 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 14:55:07 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_ennemy_list	*new_ennemy(void)
{
	t_ennemy_list	*new;

	new = malloc(sizeof(t_ennemy_list));
	if (!new)
		return (NULL);
	new->x_pos[0] = 0;
	new->x_pos[1] = 0;
	new->last_pos[0] = 0;
	new->last_pos[1] = 0;
	new->dir = -1;
	new->move_switch = 1;
	new->next = NULL;
	return (new);
}

static t_ennemy_list	*last_cell(t_so_long data)
{
	if (!data.ennemy)
		return (NULL);
	while (data.ennemy->next)
		data.ennemy = data.ennemy->next;
	return (data.ennemy);
}

void	add_back(t_so_long *data, t_ennemy_list *lst)
{
	t_ennemy_list	*end;

	if (data->ennemy)
	{
		end = last_cell(*data);
		end->next = lst;
	}
	else
		data->ennemy = lst;
}
