//
// Created by Dmytro Pylypenko on 2/9/17.
//

#include "../main/fdf.h"

fdf_point **model_map_creator(char *file)
{
	char *input_map;
	size_t *nbr_points;
	fdf_point **struct_map;

	int i = 0;
	nbr_points = 0;
	if (!(nbr_points = (size_t *)malloc(sizeof(size_t) * 2)))
	{
		ft_putstr("ERROR! THERE ARE NOT ENOUGH BRAINS IN YOUR COMPUTER! UPGRADE THIS SHIT!");
		exit(EXIT_FAILURE);
	}
	input_map = input_map_reader(file, nbr_points);
	printf("map:\n%s\n", input_map);

	nbr_points[1] = points_counter(input_map);
	printf("\nnbr_x:%zu nbr_points:%zu\n",nbr_points[0], nbr_points[1]);

	if (nbr_points[1] == 0)
	{
		ft_putstr("ERROR! THERE ARE ANY FU*kING POINT ON THE MAP!");
		exit(EXIT_FAILURE);
	}
	struct_map = struct_map_creator(input_map, nbr_points[1]);

	printf("\nAll points:");
	while (i < nbr_points[1])
	{
		printf("\nx:%f y:%f z:%f color:%d\n", struct_map[i]->x, struct_map[i]->y, struct_map[i]->z, struct_map[i]->color);
		i++;
	}

	return (0);
}
