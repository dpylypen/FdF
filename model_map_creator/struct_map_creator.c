/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map_creator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:34:35 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/04 19:50:57 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

static void	xy_generator(t_fdf_point *struct_map, size_t *nbr_points)
{
	float				xy[2];
	size_t				ij[2];
	float				step_x;
	float				step_y;

	xy[0] = -0.8f;
	xy[1] = -0.8f;
	ij[0] = 0;
	ij[1] = 0;
	step_x = 1.6f / (nbr_points[0] - 1);
	step_y = 1.6f / ((nbr_points[1] / nbr_points[0]) - 1);
	while (ij[1] < nbr_points[1])
	{
		while (ij[0] < nbr_points[0])
		{
			struct_map[ij[0] + ij[1]].x = xy[0];
			xy[0] += step_x;
			struct_map[ij[0] + ij[1]].y = xy[1];
			ij[0]++;
		}
		ij[1] += ij[0];
		ij[0] = 0;
		xy[1] += step_y;
		xy[0] = -0.8f;
	}
}

static void	cord_color_rw(char *input_map, size_t *nbr_points,
							t_fdf_point *struct_map)
{
	size_t				i;

	i = 0;
	while (i < nbr_points[1])
	{
		while (ft_isspace(*input_map))
			input_map++;
		struct_map[i].z = ((float)ft_atoi(input_map)) / 100;
		while (!ft_isspace(*input_map) && *input_map != '\0'
				&& *input_map != ',')
			input_map++;
		if (*input_map == ',')
		{
			input_map += 1;
			struct_map[i].color = hex_reader(&input_map);
		}
		else
			struct_map[i].color = 0x00ffffff;
		while (!ft_isspace(*input_map) && *input_map != '\0')
			input_map++;
		i++;
	}
}

t_fdf_point	*struct_map_creator(char *input_map, size_t *nbr_points)
{
	static t_fdf_point	*struct_map = 0;

	if (!(struct_map = (t_fdf_point *)malloc(sizeof(t_fdf_point)
						* nbr_points[1])))
	{
		ft_putstr("ERROR! COMPUTER HASN'T ENOUGH BRAINS! UPGRADE THIS SHIT!");
		exit(EXIT_FAILURE);
	}
	cord_color_rw(input_map, nbr_points, struct_map);
	struct_map[0].length = nbr_points[0];
	struct_map[0].height = nbr_points[1] / nbr_points[0];
	xy_generator(struct_map, nbr_points);
	return (struct_map);
}
