//
// Created by Dmytro Pylypenko on 2/9/17.
//

#include "../main/fdf.h"

int	elem_checker(char elem)
{
	if (ft_isdigit(elem) || elem == ',')
		return (1);
	else
		return (0);
}

size_t points_counter(char *input_map)
{
	size_t nbr_points;

	nbr_points = 0;
	while (*input_map)
	{
		while (ft_isspace(*input_map))
		{
			input_map++;
		}
		if (ft_isdigit(*input_map))
		{
			nbr_points++;
		}
		while(!(ft_isspace(*input_map)) && !(*input_map == '\0'))
		{
			if (!elem_checker(*input_map))
			{
				ft_putstr("\nERROR! THERE ARE ALIENS ON THE MAP!!! KILL THEM ALL!\n");
				exit(EXIT_FAILURE);
			}
			input_map++;
		}

	}
	return (nbr_points);
}