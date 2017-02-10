//
// Created by Dmytro Pylypenko on 2/9/17.
//

#ifndef FDF_MAP_READER_H
#define FDF_MAP_READER_H

typedef	struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					fdf_point;

//----------main model_map_creator functions----------
char *input_map_reader(char *adr, size_t *nbr_x); //reader for input map
fdf_point **model_map_creator(char *file); //main model creator
size_t points_counter(char *input_map); //counter of points
fdf_point **struct_map_creator(char *input_map, size_t nbr_points); //creator of points structures

#endif //FDF_MAP_READER_H
