/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_map_creator.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:17:30 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/02 18:37:23 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_MAP_CREATOR_H
# define MODEL_MAP_CREATOR_H

typedef	struct		s_fdf_point
{
	float			x;
	float			y;
	float			z;
	int				color;
	float			dx;
	float			dy;
	size_t			length;
	size_t			height;
}					t_fdf_point;

char				*input_map_reader(char *adr, size_t *nbr_x);
t_fdf_point			*model_map_creator(char *file);
size_t				points_counter(char *input_map);
t_fdf_point			*struct_map_creator(char *input_map, size_t *nbr_points);
int					hex_reader(char **hex);

#endif
