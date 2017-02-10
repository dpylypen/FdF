//
// Created by Dmytro Pylypenko on 2/8/17.
//algorithm Brezenham

#include "../main/fdf.h"

void draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	int error2;

	mlx_pixel_put(mlx, win, x2, y2, 0x00FFFFFF);
	while(x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0x00FFFFFF);
		error2 = error * 2;
		if(error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}

}