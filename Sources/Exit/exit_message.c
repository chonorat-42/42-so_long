/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:26:45 by chonorat          #+#    #+#             */
/*   Updated: 2023/09/27 17:08:54 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	success_message(t_so_long data)
{
	ft_putendl_fd("Congrats !", 1);
	if (data.ennemy_count)
	{
		if (data.heart == 1)
		{
			ft_putendl_fd("That was close...", 1);
			ft_printf("You made it out alive with only %d life left\n",
				data.heart);
		}
		else
			ft_printf("You made it out alive with %d lives left\n", data.heart);
	}
}

static void	failure_message(void)
{
	ft_putendl_fd("Too bad...", 1);
	ft_putendl_fd("You weren't able to make it out alive.", 1);
	ft_putendl_fd("Next time, be better.", 1);
}

void	exit_message(t_so_long *data)
{
	if (data->heart)
		success_message(*data);
	else if (!data->heart)
		failure_message();
	exit_program(data, EXIT_SUCCESS);
}
