cmake_minimum_required(VERSION 3.6)
project(FdF)

set(CMAKE_C_FLAGS "-lmlx -framework OpenGL -framework AppKit ${CMAKE_C_FLAGS}  -std=c99")

set(SOURCE_FILES main/main.c line_drawer/draw_line.c main/fdf.h model_map_creator/input_map_reader.c get_next_line/get_next_line.c model_map_creator/model_map_creator.h line_drawer/line_drawer.h model_map_creator/model_map_creator.c model_map_creator/points_counter.c model_map_creator/struct_map_creator.c)
add_executable(FdF ${SOURCE_FILES})
target_link_libraries(FdF ${CMAKE_SOURCE_DIR}/libft/libft.a)