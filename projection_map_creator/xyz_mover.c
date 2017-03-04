/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz_mover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:36:04 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/03 20:36:21 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

void	xyz_mover(t_fdf_point *proj_map, t_xyz_move move)
{
	proj_map->x = proj_map->x + move.x;
	proj_map->y = proj_map->y + move.y;
	proj_map->z = proj_map->z + move.z;
}
