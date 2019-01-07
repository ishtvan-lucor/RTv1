/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:51:27 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/07 19:50:12 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "objects.h"

# define WIN_W 900
# define WIN_H 900
# define REFLECTIVE 0
# define SPECULAR 10
/*
 * FOV - (field of view) angle of view from camera
 * to make it 60 degree: Vw = Vh = d = 1
 */
# define FOV 1

typedef struct	s_basic
{
	void		*mlx;
	void		*win;
	void		*p_to_img;
	int 		*img;
	t_is		spec; // never used)
	t_vector	cmr;
	t_list		*prim;
	t_list		*light;
}				t_basic;


void	show_obj_coord(t_basic *all);


void			start_loop_mlx(t_basic *storage);
int				init_mlx(t_basic *s);
int				vector_writer(char *c1, char *c2, char *c3, t_vector *t);
t_vector		point_from_screen_to_viewport(int x, int y);

/*
 * Validation
 */

int				validation_config(char *config, t_basic *sv);
int				val_camera(int fd, t_vector *cmr);
int				val_sphere(int fd, t_list **prim);
int				val_spot(int fd, t_list **light);
int				val_vector(char **s, t_vector *trg, size_t len);
int				val_double_cord(char **s, double *trg, size_t len);
int				val_color(char **s, t_color *trg, size_t len);
int				val_int_cord(char **s, int *trg, size_t len);

#endif
