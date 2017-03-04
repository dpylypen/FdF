/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 09:41:57 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/04 19:48:15 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	control_unit_z_zoomer(int key, t_scene *scene)
{
	if (key == 27)
		scene->z_zoom = -0.1f;
	if (key == 24)
		scene->z_zoom = +0.1f;
}

static void	control_unit_rot_reset(int key, t_scene *scene)
{
	if (key == 53)
		exit(0);
	if (key == 86)
		scene->angle->b += 5;
	if (key == 88)
		scene->angle->b -= 5;
	if (key == 91)
		scene->angle->a -= 5;
	if (key == 84)
		scene->angle->a += 5;
	if (key == 89)
		scene->angle->g -= 5;
	if (key == 92)
		scene->angle->g += 5;
	if (key == 87)
	{
		scene->angle->a = 0;
		scene->angle->b = 0;
		scene->angle->g = 0;
		scene->move->x = 0;
		scene->move->y = 0;
		scene->move->z = 0;
		scene->zoom = 600;
	}
}

int			key_press(int key, void *param)
{
	t_scene	*scene;

	scene = (t_scene*)param;
	control_unit_rot_reset(key, scene);
	control_unit_z_zoomer(key, scene);
	if (key == 69)
		scene->zoom += 20;
	if (key == 78)
	{
		if (scene->zoom > 0)
			scene->zoom -= 20;
	}
	if (key == 126)
		scene->move->y -= 20;
	if (key == 125)
		scene->move->y += 20;
	if (key == 123)
		scene->move->x -= 20;
	if (key == 124)
		scene->move->x += 20;
	scene->proj_map = projection_map_creator(scene->struct_map, *scene);
	scene->z_zoom = 0;
	img_creator(scene->proj_map, *scene);
	return (0);
}

static void	start_config_maker(t_scene *scene)
{
	if (!(scene->angle = (t_abg_rot *)malloc(sizeof(t_abg_rot) * 1)))
	{
		ft_putstr("ERROR! COMPUTER HASN'T ENOUGH BRAINS! UPGRADE THIS SHIT!");
		exit(EXIT_FAILURE);
	}
	scene->angle->a = -40;
	scene->angle->b = 0;
	scene->angle->g = -40;
	scene->zoom = 600.0;
	scene->z_zoom = 0;
	if (!(scene->move = (t_xyz_move *)malloc(sizeof(t_xyz_move) * 1)))
	{
		ft_putstr("ERROR! COMPUTER HASN'T ENOUGH BRAINS! UPGRADE THIS SHIT!");
		exit(EXIT_FAILURE);
	}
	scene->move->x = 0;
	scene->move->y = 0;
	scene->move->z = 0;
}

int			main(int argc, char **argv)
{
	t_scene scene;

	if (argc != 2)
	{
		ft_putstr("GIVE ME ONE MAP AS PARAMETER!!!");
		exit(EXIT_FAILURE);
	}
	scene.mlx = mlx_init();
	scene.win = mlx_new_window(scene.mlx, 800, 600, "FdF");
	scene.struct_map = model_map_creator(argv[1]);
	start_config_maker(&scene);
	scene.proj_map = projection_map_creator(scene.struct_map, scene);
	scene.img = mlx_new_image(scene.mlx, 800, 600);
	scene.arr = (int *)mlx_get_data_addr(scene.img, &scene.bits,
				&scene.size_line, &scene.endians);
	img_creator(scene.proj_map, scene);
	mlx_hook(scene.win, 2, 0, key_press, &scene);
	mlx_loop(scene.mlx);
	return (0);
}
