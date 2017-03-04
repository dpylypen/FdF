/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_drawer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:03:53 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/03 21:02:19 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MODEL_DRAWER_H
# define FDF_MODEL_DRAWER_H

void	img_creator(t_fdf_point *proj_map, t_scene scene);
void	img_line_drawer(t_scene scene, t_fdf_point p1, t_fdf_point p2);
int		color_maker(int *flag, t_fdf_point *p1, t_fdf_point *p2);
int		line_clipper(int flag, t_fdf_point *p1, t_fdf_point *p2);

# define LEFT 1
# define RIGHT 2
# define BOTTOM 8
# define TOP 4

#endif
