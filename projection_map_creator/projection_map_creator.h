/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_map_creator.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:19:10 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/04 18:36:59 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROJECTION_MAP_CREATOR_H
# define FDF_PROJECTION_MAP_CREATOR_H

# include "../main/fdf.h"

typedef struct	s_xyz_move
{
	float		x;
	float		y;
	float		z;
}				t_xyz_move;

typedef struct	s_abg_rot
{
	float		a;
	float		b;
	float		g;
}				t_abg_rot;

typedef struct	s_scene
{
	void		*mlx;
	void		*win;
	t_fdf_point	*struct_map;
	t_fdf_point	*proj_map;
	t_abg_rot	*angle;
	int			zoom;
	float		z_zoom;
	t_xyz_move	*move;
	void		*img;
	int			endians;
	int			bits;
	int			size_line;
	int			*arr;
}				t_scene;

t_fdf_point		*projection_map_creator(t_fdf_point *struct_map, t_scene scene);
void			abg_rotator(t_fdf_point *struct_map,
								t_fdf_point *proj_map, t_abg_rot angle);
void			zoom_scaler(t_fdf_point *proj_map, float zoom);
void			xyz_mover(t_fdf_point *proj_map, t_xyz_move move);

#endif
