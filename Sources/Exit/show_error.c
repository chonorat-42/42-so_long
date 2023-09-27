/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:23:31 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 17:27:44 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	size_error(t_so_long data)
{
	if (data.map_height == 0 && data.map_width == 0)
		ft_putendl_fd("The map is empty !", 1);
	else if (data.map_height < 3 || data.map_width < 3)
		ft_putendl_fd("Invalid size map.", 1);
	else
		ft_putendl_fd("Map's lines need to be at the same size.", 1);
}

static void	element_error(t_so_long data)
{
	if (data.player == 0)
		ft_putendl_fd("You need to have a Player.", 1);
	else if (data.player > 1)
		ft_printf("Remove %d Player. Only 1 is supported.\n", data.player - 1);
	if (data.exit == 0)
		ft_putendl_fd("You need to have an Exit.", 1);
	else if (data.exit > 1)
		ft_printf("Remove %d Exit. Only 1 is needed.\n", data.exit - 1);
	if (data.collectible == 0)
		ft_putendl_fd("You need to have at least 1 Collectible.", 1);
}

static void	map_error(char *error)
{
	ft_putendl_fd("Failed in attempting to get the map.", 1);
	if (ft_strncmp(error, "NL_ERROR", 8) == 0)
		ft_putendl_fd("'\\n' detected in map's last line.", 1);
}

void	show_error(t_so_long data, char *error)
{
	ft_putstr_fd("Error\n", 1);
	if (ft_strncmp(error, "ARGC_ERROR", 10) == 0)
		ft_putendl_fd("USAGE: ./so_long map_name.ber", 1);
	else if (ft_strncmp(error, "EXT_ERROR", 9) == 0)
		ft_putendl_fd("Wrong map extension. Use '.ber' file.", 1);
	else if (ft_strncmp(error, "MAP_ERROR", 9) == 0
		|| ft_strncmp(error, "NL_ERROR", 8) == 0)
		map_error(error);
	else if (ft_strncmp(error, "SIZE_ERROR", 10) == 0)
		size_error(data);
	else if (ft_strncmp(error, "BORDER_BREACHED", 15) == 0)
		ft_putendl_fd("There is a rift in map's limits.", 1);
	else if (ft_strncmp(error, "ELEMENT_ERROR", 13) == 0)
		element_error(data);
	else if (ft_strncmp(error, "INVALID_MAP", 11) == 0)
		ft_putendl_fd("Invalid Map. Only (0, 1, P, C, E, X) is recognized.", 1);
	else if (ft_strncmp(error, "CANNOT_COMPLETE", 15) == 0)
		ft_putendl_fd("Map cannot be completed.", 1);
	else if (ft_strncmp(error, "MLX_ERROR", 9) == 0)
		ft_putendl_fd("Something went wrong with MLX execution.", 1);
	else if (ft_strncmp(error, "XPM_ERROR", 9) == 0)
		ft_putendl_fd("Something went wrong with XPM files.", 1);
}
