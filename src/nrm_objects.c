/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nrm_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:36:28 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/26 20:02:42 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	nrm_plane(t_co *data, t_vector *d)
{
	double	tmp;

	data->nrm = ((t_plane*)(data->obj))->nrm;
	tmp = v_dot_prd(d, &data->nrm);
	if (tmp < 0)
		data->nrm = v_mult_n(&data->nrm, (-1));
}

void	nrm_sphere(t_co *data)
{
	data->nrm = v_minus(&data->hit, &((t_sphere*)(data->obj))->cntr);
	data->nrm = v_nrm(&data->nrm);
}

void	nrm_cylinder(t_co *data, t_vector *d, t_vector *o)
{
	double		m;
	t_vector	axis;
	t_vector	x;

	axis = ((t_cylinder*)(data->obj))->axis;
	x = v_minus(o, &(((t_cylinder*)(data->obj))->start));
	m = v_dot_prd(d, &axis) * data->t + v_dot_prd(&x, &axis);
	axis = v_mult_n(&axis, m);
	data->nrm = v_minus(&data->hit, &(((t_cylinder*)(data->obj))->start));
	data->nrm = v_minus(&data->nrm, &axis);
	data->nrm = v_nrm(&data->nrm);
}

void	nrm_cone(t_co *data, t_vector *d, t_vector *o)
{
	double		m;
	t_vector	axis;
	t_vector	x;

	axis = ((t_cone*)(data->obj))->axis;
	x = v_minus(o, &((t_cone*)(data->obj))->start);
	m = v_dot_prd(d, &axis) * data->t + v_dot_prd(&x, &axis);
	axis = v_mult_n(&axis, (m * (1 + pow(((t_cone*)(data->obj))->angle, 2))));
	data->nrm = v_minus(&data->hit, &(((t_cone*)(data->obj))->start));
	data->nrm = v_minus(&data->nrm, &axis);
}
