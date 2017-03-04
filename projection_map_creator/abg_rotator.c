/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abg_rotator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:23:46 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/03 21:03:23 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

void	abg_rotator(t_fdf_point *s_map, t_fdf_point *p_map, t_abg_rot angle)
{
	float x;
	float y;
	float z;

	x = s_map->x;
	y = s_map->y;
	z = s_map->z;
	p_map->x = (x * (cosf(angle.b * 3.14f / 180.0f) * cosf(angle.g
					* 3.14f / 180.0f))) + (y * cosf(angle.b * 3.14f / 180.0f)
					* -sinf(angle.g * 3.14f / 180.0f))
					+ (z * -sinf(angle.b * 3.14f / 180.0f));
	p_map->y = (x * ((sinf(angle.a * 3.14f / 180.0f) * sinf(angle.b * 3.14f
					/ 180.0f) * cosf(angle.g * 3.14f / 180.0f)) + (cosf(angle.a
					* 3.14f / 180.0f) * sinf(angle.g * 3.14f / 180.0f)))) + (y
					* ((sinf(angle.a * 3.14f / 180.0f) * sinf(angle.b
					* 3.14f / 180.0f) * -sinf(angle.g * 3.14f / 180.0f))
					+ (cosf(angle.a * 3.14f / 180.0f) * cosf(angle.g * 3.14f
					/ 180.0f)))) + (z * sinf(angle.a * 3.14f / 180.0f)
					* cosf(angle.b * 3.14f / 180.0f));
}
