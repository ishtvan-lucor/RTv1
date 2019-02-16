/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usable_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:05:07 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/16 21:31:13 by ikoloshy         ###   ########.fr       */
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
# define DELIMITR "+"

typedef enum	e_rgb
{
	RED,
	GREEN,
	BLUE
}				t_rgb;

typedef union	u_color
{
	int 		color;
	UC			clr[3];
}				t_color;

typedef struct	s_image_specification
{
	int 		bpp;
	int 		sl;
	int 		endl;
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
	int			color;
	int			spcl;
	double		rfl;
	double		t;
	t_vector	hit;
	t_vector	nrm;
	t_vector	rvrs_drct;
}				t_co;
#endif
