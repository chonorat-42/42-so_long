/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:31:16 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/22 14:51:31 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int	print_move(t_so_long *data)
{
	char	*move_str;
	char	*count;

	count = ft_itoa(data->move_count);
	if (!count)
		return (show_error(*data, "NULL"), exit_program(data, 64));
	move_str = ft_strjoin("Movement Count : ", count);
	if (!move_str)
		return (free(count), show_error(*data, "NULL"), exit_program(data, 65));
	mlx_string_put(data->mlx, data->win, 32, (data->map_height * 32) - 12,
		0x00FFFFFF, move_str);
	free(count);
	free(move_str);
	return (1);
}
