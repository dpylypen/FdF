//
// Created by Dmytro Pylypenko on 2/9/17.
//

#include "../main/fdf.h"

float xy_generator(char value, size_t i)
{
	static float x = 10;
	static float y =
	float	cur_x;

	if (value == 'x')
		return (xy);
	if (value == 'y')
	{
		cur_value = xy;
		xy += 10;
		return (cur_value);
	}
}

fdf_point **struct_map_creator(char *input_map, size_t nbr_points)
{
	size_t i;
	fdf_point **struct_map;

	i = 0;
	struct_map = 0;
	if (!(struct_map = (fdf_point **)malloc(sizeof(fdf_point *) * nbr_points)))
	{
		ft_putstr("ERROR! THERE ARE NOT ENOUGH BRAINS IN YOUR COMPUTER! UPGRADE THIS SHIT!");
		exit(EXIT_FAILURE);
	}
	while (i < nbr_points)
	{
		while (ft_isspace(*input_map))
			input_map++;
		if (!(struct_map[i] = (fdf_point *) malloc(sizeof(fdf_point))))
		{
			ft_putstr("ERROR! THERE ARE NOT ENOUGH BRAINS IN YOUR COMPUTER! UPGRADE THIS SHIT!");
			exit(EXIT_FAILURE);
		}
		struct_map[i]->x = xy_generator('x'); // xy_generator
		struct_map[i]->y = xy_generator('y'); // xy_generator
		struct_map[i]->z = (float)ft_atoi(input_map);
		struct_map[i]->color = 0x00FFFFFF;
		while (!ft_isspace(*input_map) && !(*input_map == '\0'))
			input_map++;
		i++;
	}
	return (struct_map);
}
