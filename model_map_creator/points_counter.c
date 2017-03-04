/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:13:14 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/02 18:16:52 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

int		elem_checker(char elem)
{
	if (ft_isdigit(elem) || elem == ',' || elem == ','
		|| elem == 'x' || elem == '-' || elem == 'A'
		|| elem == 'B' || elem == 'C' || elem == 'D'
		|| elem == 'E' || elem == 'F' || elem == 'a'
		|| elem == 'b' || elem == 'c' || elem == 'd'
		|| elem == 'e' || elem == 'f')
		return (1);
	else
		return (0);
}

size_t	points_counter(char *input_map)
{
	size_t nbr_points;

	nbr_points = 0;
	while (*input_map)
	{
		while (ft_isspace(*input_map))
		{
			input_map++;
		}
		if (ft_isdigit(*input_map) || *input_map == '-')
		{
			nbr_points++;
		}
		while (!(ft_isspace(*input_map)) && !(*input_map == '\0'))
		{
			if (!elem_checker(*input_map))
			{
				ft_putstr("\nERROR! ALIENS ON THE MAP!!! KILL THEM ALL!");
				exit(EXIT_FAILURE);
			}
			input_map++;
		}
	}
	return (nbr_points);
}
