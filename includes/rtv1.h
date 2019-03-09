/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:51:27 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/09 16:42:43 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "objects.h"

# define WIN_W 1200
# define WIN_H 1200
# define INFINITY_RAY_DIST 1000000000.0
# define START_OF_VIEWPORT 1.0
# define START_NEAR_SURFACE 0.00000001
# define BACKGROUND_COLOR 0x000000
# define DEPTH 10

/*
** FOV - (field of view) angle of view from camera
** to make it 60 degree: Vw = Vh = d = 1
*/
# define FOV 1

typedef struct	s_basic
{
	void		*mlx;
	void		*win;
	void		*p_to_img;
	int			*img;
	int			rot_x;
	int			rot_y;
	t_is		spec;
	t_vector	cmr;
	t_list		*prim;
	t_list		*light;
}				t_basic;

void			start_loop_mlx(t_basic *storage);
void			render(t_basic *s);
void			get_closest_object(t_co *obj, t_data_tr *data,
				const t_list *entity);
int				init_mlx(t_basic *s);
int				trace_ray(t_data_tr *d, const t_list *obj,
				const t_list *light, int depth);
double			calc_intensity(t_co *point_data, t_data_tr *data,
				const t_list *light, const t_list *prim);
t_vector		reflection_ray(const t_vector *drct, const t_vector *nrm);
int				analyze_light(t_list *light);
int				analyze_prim(t_list *list);

/*
** Intersection whith obj
*/

t_hs			sphere_intersection(t_vector *o, t_vector *d, const void *obj);
t_hs			plane_intersection(t_vector *o, t_vector *d, const void *obj);
t_hs			cylinder_intersection(t_vector *o, t_vector *d,
				const void *obj);
t_hs			cone_intersection(t_vector *o, t_vector *d, const void *obj);

/*
** Find normal
*/

void			nrm_plane(t_co *data, t_vector *d);
void			nrm_sphere(t_co *data);
void			nrm_cylinder(t_co *data, t_vector *d, t_vector *o);
void			nrm_cone(t_co *data, t_vector *d, t_vector *o);

/*
** Validation
*/

int				validation_config(char *config, t_basic *sv);
int				val_camera(int fd, t_vector *cmr, int *rot_x, int *rot_y);

/*
** Objects
*/

int				val_sphere(int fd, t_list **prim);
int				val_plane(int fd, t_list **prim);
int				val_cylinder(int fd, t_list **prim);
int				val_cone(int fd, t_list **prim);

/*
** Lights
*/

int				val_spot(int fd, t_list **light);
int				val_ambient(int fd, t_list **light);
int				val_dls(int fd, t_list **light);

/*
** Validate parameters
*/

int				val_vector(char **s, t_vector *trg, size_t len);
int				val_double_cord(char **s, double *trg, size_t len);
int				val_color(char **s, t_color *trg, size_t len);
int				val_int_cord(char **s, int *trg, size_t len);
int				vector_writer(char *c1, char *c2, char *c3, t_vector *t);

#endif
