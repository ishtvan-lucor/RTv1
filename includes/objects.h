/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:02:04 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/19 13:18:39 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "usable_structs.h"

typedef enum	e_obj
{
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	SPOT,
	DLS,
	AMBIENT
}				t_obj;

typedef struct	s_abstract_prim
{
	t_color		clr;
	int			spcl;
	double		rfl;
}				t_aprm;

typedef struct	s_abstract_light
{
	double		intensity;
}				t_alght;

typedef struct	s_ambient
{
	double		intensity;
}				t_ambient;

typedef struct	s_spot
{
	double		intensity;
	t_vector	position;
}				t_spot;

typedef struct	s_dls
{
	double		intensity;
	t_vector	direction;
}				t_dls;

typedef struct	s_sphere
{
	t_color		clr;
	int			spcl;
	double		rfl;
	double		rds;
	t_vector	cntr;
}				t_sphere;

typedef struct	s_plane
{
	t_color		clr;
	int			spcl;
	double		rfl;
	t_vector	point;
	t_vector	nrm;
}				t_plane;

typedef struct	s_cylinder
{
	t_color		clr;
	int			spcl;
	double		rfl;
	double		rds;
	t_vector	start;
	t_vector	axis;
}				t_cylinder;

typedef struct	s_cone
{
	t_color		clr;
	int			spcl;
	double		rfl;
	double		angle;
	t_vector	start;
	t_vector	axis;
}				t_cone;

#endif
