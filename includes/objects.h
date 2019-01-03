/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:02:04 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/12/26 17:48:38 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "usable_structs.h"
# include "../libft/libft.h"

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
	float		intensity;
	t_vector	position;
}				t_spot;

typedef struct	s_sphere
{
	char		obj;
	t_color		clr;
	double		r;
	t_vector	c;
}				t_sphere;

#endif
