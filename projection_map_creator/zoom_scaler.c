/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_scaler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:37:00 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/03 20:37:12 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

void	zoom_scaler(t_fdf_point *proj_map, float zoom)
{
	proj_map->x = proj_map->x * zoom;
	proj_map->y = proj_map->y * zoom;
	proj_map->z = proj_map->z * zoom;
}
