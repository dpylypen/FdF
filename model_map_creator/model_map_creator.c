/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_map_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:43:56 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/02 18:12:45 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

t_fdf_point		*model_map_creator(char *file)
{
	char		*input_map;
	size_t		*nbr_points;
	t_fdf_point	*struct_map;

	nbr_points = 0;
	if (!(nbr_points = (size_t *)malloc(sizeof(size_t) * 2)))
	{
		ft_putstr("ERROR!COMPUTER HASN'T ENOUGH BRAINS! UPGRADE THIS SHIT!");
		exit(EXIT_FAILURE);
	}
	input_map = input_map_reader(file, nbr_points);
	nbr_points[1] = points_counter(input_map);
	if (nbr_points[1] == 0)
	{
		ft_putstr("ERROR! THERE ARE ANY FU*kING POINT ON THE MAP!");
		exit(EXIT_FAILURE);
	}
	struct_map = struct_map_creator(input_map, nbr_points);
	free(input_map);
	free(nbr_points);
	return (struct_map);
}
