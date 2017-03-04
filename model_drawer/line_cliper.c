/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cliper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:03:06 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/03 21:01:34 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

static char	get_code(float *rb, t_fdf_point *p)
{
	char	ret_code;

	ret_code = 0;
	if (p->dx < 1)
		ret_code |= LEFT;
	else if (p->dx > rb[0] - 1)
		ret_code |= RIGHT;
	if (p->dy < 1)
		ret_code |= TOP;
	else if (p->dy > rb[1] - 1)
		ret_code |= BOTTOM;
	return (ret_code);
}

static int	clip_tb(t_fdf_point *p1, float max, t_fdf_point *p2, char code)
{
	float m;

	m = (p2->dx - p1->dx) / (p2->dy - p1->dy);
	if (m != m)
		m = 0;
	if (code & TOP)
	{
		p1->dx += m * (1 - p1->dy);
		p1->dy = 1;
		return (1);
	}
	if (code & BOTTOM)
	{
		p1->dx += m * (max - p1->dy);
		p1->dy = max;
		return (1);
	}
	return (0);
}

static void	clip_lr(t_fdf_point *p1, float max, t_fdf_point *p2, char code)
{
	float m;

	m = (p2->dy - p1->dy) / (p2->dx - p1->dx);
	if (m != m)
		m = 0;
	if (code & RIGHT)
	{
		p1->dy += m * (max - p1->dx);
		p1->dx = max;
	}
	else if (code & LEFT)
	{
		p1->dy += m * (1 - p1->dx);
		p1->dx = 1;
	}
}

static int	clip_point(float *rb, t_fdf_point *p1, t_fdf_point *p2, char code)
{
	if (!code)
		return (0);
	if (!clip_tb(p1, rb[1] - 1, p2, code))
		clip_lr(p1, rb[0] - 1, p2, code);
	return (1);
}

int			line_clipper(int flag, t_fdf_point *p1, t_fdf_point *p2)
{
	char	code_p1;
	char	code_p2;
	float	rb[2];

	rb[0] = 800;
	rb[1] = 600;
	if (flag)
	{
		p1->dx = p1->x;
		p1->dy = p1->y;
		p2->dx = p2->x;
		p2->dy = p2->y;
		flag = 0;
	}
	code_p1 = get_code(rb, p1);
	code_p2 = get_code(rb, p2);
	if (!(code_p1 | code_p2))
		return (1);
	if (code_p1 & code_p2)
		return (0);
	if (clip_point(rb, p1, p2, code_p1) && !line_clipper(flag, p1, p2))
		return (0);
	if (clip_point(rb, p2, p1, code_p2) && !line_clipper(flag, p2, p1))
		return (0);
	return (1);
}
