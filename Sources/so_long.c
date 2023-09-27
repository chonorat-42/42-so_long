/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:45:45 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 16:53:22 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

static int	check_extension(char *map)
{
	int	index;

	index = ft_strlen(map) - 4;
	if (ft_strncmp(&map[index], ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_so_long	data;
	int			error;

	error = 1;
	init_data(&data);
	if (argc == 2)
	{
		if (!check_extension(argv[1]))
			return (show_error(data, "EXT_ERROR"), 2);
		error = get_map(&data, argv);
		if (error)
			return (show_error(data, "MAP_ERROR"), free_data(&data), error);
		error = check_map(&data);
		if (error)
			return (free_data(&data), error);
		if (!mlx_window(&data))
			return (show_error(data, "MLX_ERROR"), free_data(&data), 13);
	}
	else
		return (show_error(data, "ARGC_ERROR"), 1);
	return (EXIT_SUCCESS);
}
