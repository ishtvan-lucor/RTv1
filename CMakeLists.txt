cmake_minimum_required(VERSION 3.12)
project(RTv1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

#add_library(libft STATIC IMPORTED)
#add_library(minilibx_macos STATIC IMPORTED)
include_directories(includes libft/includes minilibx_macos)
link_directories(libft minilibx_macos)
find_library(OPENGL OpenGl)
find_library(APPKIT AppKit)

add_executable(RTv1
        libft/libft.h
        minilibx_macos/mlx.h
        includes/rtv1.h
        includes/objects.h
        includes/usable_structs.h
        src/main.c
        src/init_mlx.c
        src/start_loop_mlx.c
        src/validation_config.c
        src/val_camera.c
        src/val_sphere.c
        src/val_data_for_obj.c
        src/val_spot.c
        src/val_ambient.c
        src/val_dls.c
        src/render.c
        src/trace_ray.c
        src/reflection_ray.c
        src/calc_intensity.c
        src/get_closest_object.c
        src/intersection.c
        src/val_plane.c
        src/val_cylinder.c
        src/val_cone.c
        src/nrm_objects.c src/right_parameters_obj.c)

#set_property(TARGET libft PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
#set_property(TARGET minilibx_macos PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/minilibx-macos/mlx.a)
target_link_libraries(RTv1 -lft -lmlx ${OPENGL} ${APPKIT})