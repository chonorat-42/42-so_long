/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:26:06 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 17:00:23 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static int	check_nl(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (0);
		index++;
	}
	return (1);
}

static int	get_height(char *dir)
{
	int		fd;
	int		line;
	int		valid_map;
	char	*str;

	line = 0;
	valid_map = 0;
	fd = open(dir, O_RDONLY);
	while (fd)
	{
		str = get_next_line(fd);
		if (str)
		{
			line++;
			valid_map = check_nl(str);
			free(str);
		}
		else if (!str)
			fd = close(fd);
	}
	if (!valid_map && line > 1)
		return (-1);
	return (line);
}

static int	ber_to_map(t_so_long *data, int fd)
{
	int		index;
	char	*temp_map;

	index = 0;
	temp_map = NULL;
	while (index < data->map_height)
	{
		temp_map = get_next_line(fd);
		if (!temp_map)
			return (close(fd), 6);
		data->map[index] = ft_strtrim(temp_map, "\n");
		free(temp_map);
		if (!data->map[index++])
			return (close(fd), 7);
	}
	close(fd);
	data->map[index] = NULL;
	return (0);
}

int	get_map(t_so_long *data, char *argv[])
{
	int		fd;
	int		error;
	char	*temp_map;

	temp_map = NULL;
	temp_map = ft_strjoin("Maps/", argv[1]);
	if (!temp_map)
		return (3);
	fd = open(temp_map, O_RDONLY);
	if (fd == -1)
		return (free(temp_map), 4);
	data->map_height = get_height(temp_map);
	free(temp_map);
	if (data->map_height == -1)
		return (show_error(*data, "NL_ERROR"), free_data(data), exit(4), 4);
	data->map = malloc((data->map_height + 1) * sizeof(char *));
	if (!data->map)
		return (close(fd), 5);
	error = ber_to_map(data, fd);
	if (error)
		return (error);
	return (0);
}
