/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_reader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:46:37 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/02 18:09:13 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

size_t	line_checker(char *line)
{
	static int		flag = 0;
	static size_t	nbr_x;

	if (!flag++)
		nbr_x = points_counter(line);
	else
	{
		if (points_counter(line) != nbr_x && points_counter(line) != 0)
		{
			ft_putstr("ERROR! THE FU*KING LINES HAVE NOT THE SAME LENGTH!");
			exit(EXIT_FAILURE);
		}
	}
	return (nbr_x);
}

char	*input_map_reader(char *adr, size_t *nbr_x)
{
	int		des;
	char	*map;
	int		flag;

	map = "\0";
	des = open(adr, O_RDONLY);
	if ((flag = get_next_line(des, &adr)) == 0)
	{
		ft_putstr("ERROR! THE FILE IS EMPTY, MOTHERFU*KER!");
		exit(EXIT_FAILURE);
	}
	else if (flag == -1)
	{
		ft_putstr("ERROR! THE FILE IS DOGSHIT! GIVE ME GOOD MAP!");
		exit(EXIT_FAILURE);
	}
	*nbr_x = line_checker(adr);
	map = ft_strjoin(map, adr);
	while (get_next_line(des, &adr))
	{
		line_checker(adr);
		map = ft_strjoin(map, " ");
		map = ft_strjoin(map, adr);
	}
	return (map);
}
