/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_line_drawer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:02:28 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/04 14:25:04 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

static void	xy_params_init(t_fdf_point p1, t_fdf_point p2, int *xy, int *params)
{
	xy[0] = (int)p1.dx;
	xy[1] = (int)p1.dy;
	xy[2] = (int)p2.dx;
	xy[3] = (int)p2.dy;
	params[0] = abs(xy[2] - xy[0]);
	params[1] = abs(xy[3] - xy[1]);
	if (xy[0] < xy[2])
		params[2] = 1;
	else
		params[2] = -1;
	if (xy[1] < xy[3])
		params[3] = 1;
	else
		params[3] = -1;
	params[4] = params[0] - params[1];
	params[5] = 0;
}

void		img_line_drawer(t_scene scene, t_fdf_point p1, t_fdf_point p2)
{
	int	xy[4];
	int	params[6];
	int	flag;

	xy_params_init(p1, p2, xy, params);
	flag = 1;
	scene.arr[((scene.size_line / 4) * xy[3]) + xy[2]] = p2.color;
	while (xy[0] != xy[2] || xy[1] != xy[3])
	{
		scene.arr[((scene.size_line / 4) * xy[1]) + xy[0]] = color_maker(&flag,
																	&p1, &p2);
		params[5] = params[4] * 2;
		if (params[5] > -params[1])
		{
			params[4] -= params[1];
			xy[0] += params[2];
		}
		if (params[5] < params[0])
		{
			params[4] += params[0];
			xy[1] += params[3];
		}
	}
}
