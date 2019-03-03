/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usable_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:05:07 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/03 18:08:39 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USABLE_STRUCTS_H
# define USABLE_STRUCTS_H

# include "../libft/libft.h"

# define UC unsigned char
# define CMR "camera"
# define CNTR "center"
# define RDS "radius"
# define CLR "color"
# define RFL "reflective"
# define SPC "specular"
# define INTN "intensity"
# define PSTN "position"
# define NRM "normal"
# define POINT "point"
# define AXIS "axis"
# define ANGLE "angle"
# define ROT_X "rotationX"
# define ROT_Y "rotationY"
# define DELIMITR "+"

typedef enum	e_rgb
{
	RED,
	GREEN,
	BLUE
}				t_rgb;

typedef enum	e_val_intersection
{
	DOT_DV,
	DOT_XV,
	KK1
}				t_vi;

typedef union	u_color
{
	int			color;
	UC			clr[3];
}				t_color;

typedef struct	s_image_specification
{
	int			bpp;
	int			sl;
	int			endl;
}				t_is;

typedef struct	s_data_tr
{
	double		min;
	double		max;
	t_vector	start;
	t_vector	direction;
}				t_data_tr;

typedef struct	s_closet_object
{
	void		*obj;
	size_t		type;
	int			color;
	int			spcl;
	double		rfl;
	double		t;
	t_vector	hit;
	t_vector	nrm;
	t_vector	rvrs_drct;
}				t_co;

typedef struct	s_hit_surface
{
	double		t1;
	double		t2;
}				t_hs;

typedef struct	s_values
{
	double		a;
	double		b;
	double		c;
	double		dscr;
}				t_values;

#endif
