//
// Created by Dmytro Pylypenko on 2/8/17.
//

#include "../main/fdf.h"

size_t line_checker(char *line)
{
	static int flag = 0;
	static size_t nbr_x;

	if (!flag)
	{
		nbr_x = points_counter(line);
		flag++;
	}
	else
	{
		if (points_counter(line) != nbr_x && points_counter(line) != 0)
		{
			ft_putstr("ERROR! THE FU*KING LINES HAVE NOT THE SAME LENGTH! CHECK IT!");
			exit(EXIT_FAILURE);
		}
	}
	return (nbr_x);
}


char *input_map_reader(char *adr, size_t *nbr_x)
{
	int des;
	char *map = "\0";
	char *tmp;
	int flag;

	des = open(adr, O_RDONLY);
	if ((flag = get_next_line(des, &tmp)) == 0)
	{
		ft_putstr("ERROR! THE FILE IS EMPTY, MOTHERFU*KER!");
		exit(EXIT_FAILURE);
	}
	else if (flag == -1)
	{
		ft_putstr("ERROR! THE FILE IS DOGSHIT! GIVE ME GOOD MAP!");
		exit(EXIT_FAILURE);
	}
	*nbr_x = line_checker(tmp);
	map = ft_strjoin(map, tmp);
	while (get_next_line(des, &tmp))
	{
			line_checker(tmp);
			map = ft_strjoin(map, " ");
			map = ft_strjoin(map, tmp);
	}
	return (map);
}

