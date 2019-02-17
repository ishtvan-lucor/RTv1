/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   culc_intensity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:13:06 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/16 22:41:31 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	diffuse(double bright, const t_vector *nrm, t_vector *drct)
{
	double	diff;

	diff = v_dot_prd(nrm, drct);
	if (diff <= 0)
		return (0.0);
	diff = diff * bright / (v_len(nrm) * v_len(drct));
	return (diff);
}

static double	shine(const t_co *data, t_vector *drct, double bright)
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

static double	culc_effects(const t_co *point, t_data_tr *d, void *light, const t_list *prim)
{
	double	res;
	double	bright;
	t_co	test;

	res = 0.0;
	get_closest_object(&test, d, prim);
	if (test.obj)
		return (res);
	bright = ((t_alght*)(light))->intensity;
	res += diffuse(bright, &point->nrm, &d->direction);
	if (point->spcl > 0)
		res += shine(point, &d->direction, bright);
	return (res);
}

//TODO optimization: use the same struct s_closet_object

double			culc_intensity(const t_co *point, const t_list *light, const t_list *prim)
{
	double		intensity;
	t_data_tr	d;

	d.start = point->hit;
	d.min = START_NEAR_SURFACE;
	intensity = 0.0;
	while (light)
	{
		if (light->content_size == AMBIENT)
		{
			intensity = ((t_alght *) (light->content))->intensity;
			light = light->next;
			continue ;
		}
		if (light->content_size == SPOT)
		{
			d.direction = v_minus(&((t_spot*)(light->content))->position, &d.start);
			d.max = 1.0;
		}
		else if (light->content_size == DLS)
		{
			d.direction = ((t_dls*)(light->content))->direction;
			d.max = INFINITY_RAY_DIST;
		}
		intensity += culc_effects(point, &d, light->content, prim);
		light = light->next;
	}
	if (intensity > 1.0)
		return (1.0);
	return (intensity);
}