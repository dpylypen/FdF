/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_map_creator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:29:25 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/04 18:56:52 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

t_fdf_point	*projection_map_creator(t_fdf_point *struct_map, t_scene scene)
{
	size_t				i;
	static t_fdf_point	*proj_map = 0;

	i = -1;
	if (proj_map == 0)
		if (!(proj_map = (t_fdf_point *)malloc(sizeof(t_fdf_point) *
			(struct_map[0].height * struct_map[0].length))))
		{
			ft_putstr("ERROR! COMPUTER HASN'T ENOUGH BRAINS! UPGRADE SHIT!");
			exit(EXIT_FAILURE);
		}
	while (++i < (struct_map[0].height * struct_map[0].length))
	{
		if ((struct_map[i].z != 0) && (struct_map[i].z != -scene.z_zoom))
			struct_map[i].z = struct_map[i].z + scene.z_zoom;
		abg_rotator(&struct_map[i], &proj_map[i], *scene.angle);
		zoom_scaler(&proj_map[i], scene.zoom);
		xyz_mover(&proj_map[i], *scene.move);
		proj_map[i].color = struct_map[i].color;
		proj_map[i].x = (int)floorf((proj_map[i].x * 0.5f + 0.5f) + 400);
		proj_map[i].y = (int)floorf((proj_map[i].y * 0.5f + 0.5f) + 300);
	}
	proj_map[0].length = struct_map[0].length;
	proj_map[0].height = struct_map[0].height;
	return (proj_map);
}
