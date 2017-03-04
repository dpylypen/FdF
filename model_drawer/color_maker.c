/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:39:20 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/04 14:00:30 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

static float	*step_maker(float *len, float *rgb_1,
							t_fdf_point *p1, t_fdf_point *p2)
{
	float			rgb_2[3];
	static float	color_step[3] = {0, 0, 0};

	*len = fabsf(p2->dx - p1->dx) + fabsf(p2->dy - p1->dy);
	rgb_1[0] = (p1->color & 0xFF0000) >> 16;
	rgb_1[1] = (p1->color & 0x00FF00) >> 8;
	rgb_1[2] = (p1->color & 0x0000FF);
	rgb_2[0] = (p2->color & 0xFF0000) >> 16;
	rgb_2[1] = (p2->color & 0x00FF00) >> 8;
	rgb_2[2] = (p2->color & 0x0000FF);
	color_step[0] = (rgb_2[0] - rgb_1[0]) / *len;
	color_step[1] = (rgb_2[1] - rgb_1[1]) / *len;
	color_step[2] = (rgb_2[2] - rgb_1[2]) / *len;
	return (color_step);
}

int				color_maker(int *flag, t_fdf_point *p1, t_fdf_point *p2)
{
	float			len;
	static float	rgb_1[3] = {0, 0, 0};
	static float	*color_step;
	int				col[3];

	if (*flag != 0)
	{
		color_step = step_maker(&len, rgb_1, p1, p2);
		*flag = 0;
	}
	else
	{
		rgb_1[0] += color_step[0];
		rgb_1[1] += color_step[1];
		rgb_1[2] += color_step[2];
	}
	col[0] = (int)rgb_1[0];
	col[1] = (int)rgb_1[1];
	col[2] = (int)rgb_1[2];
	return ((col[0] << 16) +
			(col[1] << 8) + col[2]);
}
