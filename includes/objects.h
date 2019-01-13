/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:02:04 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/10 21:04:32 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "usable_structs.h"

# define REFLECTIVE 0
# define SPECULAR 10

typedef enum	e_obj
{
	SPOT,
	SPHERE = 10,
	PLANE,
	CONE,
	CYLINDER
}				t_obj;

typedef struct	s_spot
{
	double		intensity;
	t_vector	position;
}				t_spot;

typedef struct	s_sphere
{
	t_color		clr;
	int			spcl;
	double		rds;
	double		rfl;
	t_vector	cntr;
}				t_sphere;

#endif
