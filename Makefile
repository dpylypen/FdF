#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 18:46:56 by dpylypen          #+#    #+#              #
#    Updated: 2017/03/04 15:49:16 by dpylypen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = main/

SRCS =	main/main.c\
		get_next_line/get_next_line.c\
		model_map_creator/input_map_reader.c\
		model_map_creator/model_map_creator.c\
		model_map_creator/points_counter.c\
		model_map_creator/struct_map_creator.c\
		model_map_creator/hex_reader.c\
		projection_map_creator/projection_map_creator.c\
		projection_map_creator/zoom_scaler.c\
		projection_map_creator/xyz_mover.c\
		projection_map_creator/abg_rotator.c\
		model_drawer/img_creator.c\
		model_drawer/img_line_drawer.c\
		model_drawer/line_cliper.c\
		model_drawer/color_maker.c

HEADERS = main/fdf.h\
        get_next_line/get_next_line.h\
        model_map_creator/model_map_creator.h\
        projection_map_creator/projection_map_creator.h\
        model_drawer/model_drawer.h

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft -lmlx -framework OpenGL -framework AppKit 

%.o: srcs/filereader/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

%.o: srcs/tetriminos/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

%.o: srcs/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libft.a: libft/Makefile
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR) 

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR) 

re:  fclean all
	make re -C $(LIBFTDIR)

norm:
	norminette $(HEADERS)
	norminette $(SRCS)
	make norm -C $(LIBFTDIR)

rmsh:
	find . -name ".DS*" -o -name "._.*" -o -name "#*" -o -name "*~" -o -name "*.out" > rmsh
	xargs rm < rmsh
	rm rmsh