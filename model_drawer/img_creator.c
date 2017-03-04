/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:50:28 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/04 16:01:22 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

static void	line_draw_controller(t_fdf_point *proj_map, t_scene scene,
									size_t i, size_t nbr_points)
{
	while (i < ((nbr_points) - 1))
	{
		if (i >= (nbr_points - proj_map[0].length) && (i + 1) < nbr_points)
		{
			if (line_clipper(1, &proj_map[i], &proj_map[i + 1]))
				img_line_drawer(scene, proj_map[i], proj_map[i + 1]);
		}
		else if (((i + 1) % proj_map[0].length == 0) && (i + 1) != nbr_points)
		{
			if (line_clipper(1, &proj_map[i], &proj_map[i
				+ proj_map[0].length]))
				img_line_drawer(scene, proj_map[i], proj_map[i
				+ proj_map[0].length]);
		}
		else
		{
			if (line_clipper(1, &proj_map[i], &proj_map[i + 1]))
				img_line_drawer(scene, proj_map[i], proj_map[i + 1]);
			if (line_clipper(1, &proj_map[i], &proj_map[i
				+ proj_map[0].length]))
				img_line_drawer(scene, proj_map[i], proj_map[i
				+ proj_map[0].length]);
		}
		i++;
	}
}

void		img_creator(t_fdf_point *proj_map, t_scene scene)
{
	size_t	i;

	i = 0;
	ft_memset(scene.arr, 0, (800 * 600) * 4);
	line_draw_controller(proj_map, scene, i, proj_map[0].length *
							proj_map[0].height);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.img, 0, 0);
}
