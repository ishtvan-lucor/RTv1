/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_intensity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:13:06 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/05 21:58:13 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static double	diffuse(double bright, const t_vector *nrm, t_vector *drct)
{
	double	diff;

	diff = v_dot_prd(nrm, drct);
	if (diff <= 0)
		return (0.0);
	diff = diff * bright / (v_len(nrm) * v_len(drct));
	return (diff);
}

static double	shine(t_co *data, t_vector *drct, double bright)
{
	double		shine;
	t_vector	reflect_ray;

	reflect_ray = reflection_ray(drct, &data->nrm);
	shine = v_dot_prd(&reflect_ray, &data->rvrs_drct);
	if (shine <= 0)
		return (0.0);
	shine = shine / (v_len(&reflect_ray) * v_len(&data->rvrs_drct));
	shine = pow(shine, data->spcl) * bright;
	return (shine);
}

static double	calc_effects(t_co *point, t_data_tr *d, void *light,
	const t_list *prim)
{
	double	res;

	res = 0.0;
	get_closest_object(point, d, prim);
	if (point->obj)
		return (res);
	res += diffuse(((t_alght*)(light))->intensity, &point->nrm, &d->direction);
	if (point->spcl > 0)
		res += shine(point, &d->direction, ((t_alght*)(light))->intensity);
	return (res);
}

static void		set_data(t_data_tr *data, double max, t_vector direction)
{
	data->max = max;
	data->direction = direction;
}

double			calc_intensity(t_co *point_data, t_data_tr *data,
	const t_list *light, const t_list *prim)
{
	double		intensity;

	intensity = 0.0;
	data->start = point_data->hit;
	data->min = START_NEAR_SURFACE;
	while (light)
	{
		if (light->content_size == AMBIENT)
		{
			intensity = ((t_alght *)(light->content))->intensity;
			light = light->next;
			continue ;
		}
		if (light->content_size == SPOT)
			set_data(data, 1.0, v_minus(&((t_spot*)(light->content))->position,
				&data->start));
		else if (light->content_size == DLS)
			set_data(data, INFINITY_RAY_DIST,
				((t_dls*)(light->content))->direction);
		intensity += calc_effects(point_data, data, light->content, prim);
		light = light->next;
	}
	if (intensity > 1.0)
		return (1.0);
	return (intensity);
}
