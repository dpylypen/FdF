/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 09:41:57 by dpylypen          #+#    #+#             */
/*   Updated: 2017/02/08 13:50:02 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"


int main(int argc, char **argv)
{
	//void	*mlx;
	//void	*win;
	//char	*map;
	//char 	*name_map = "/nfs/2016/d/dpylypen/CLion/ClionProjects/FdF/maps/42.fdf";

	model_map_creator(argv[1]);
//	mlx = mlx_init();
//	map = read_map(name_map);
//	printf("%s", map);
//	win = mlx_new_window(mlx, 800, 600, "FdF");

	/*
	void * img = mlx_new_image(mlx,800,600);
	int endian;
	int bits;
	int size_line;
	int *arr = (int *)mlx_get_data_addr(img,&bits,&size_line,&endian);
	//arr[2500] = 0xFF0000;
	ft_memset(arr, 0x00FFFF, 400);
	size_t i = -1;
	while(++i < 400)
	{
		size_t j = -1;
		while(++j < 400)
			arr[i * 800 + j] = 0xFF0000;
	}
	mlx_put_image_to_window(mlx,win,img,0,0);
*/
/*
	draw_line(mlx, win, 20, 20, 100, 100);
	draw_line(mlx, win, 20, 20, 20, 200);
	draw_line(mlx, win, 20, 200, 100, 300);
	draw_line(mlx, win, 100, 100, 100, 300);
	draw_line(mlx, win, 20, 20, 200, 20);
	draw_line(mlx, win, 200, 20, 280, 100);
	draw_line(mlx, win, 100, 100, 280, 100);
	draw_line(mlx, win, 280, 100, 280, 300);
	draw_line(mlx, win, 280, 300, 100, 300);
 */
//	mlx_loop(mlx);
    return (0);
}
