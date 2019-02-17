/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:50:47 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/17 15:28:16 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_hs	sphere_intersection(t_vector *o, t_vector *d, const void *obj)
{
	double		r;
	t_vector	oc;
	t_values	val;
	t_hs		hits;
	double		discrim;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	r = ((t_sphere*)(obj))->rds;
	oc = ((t_sphere*)(obj))->cntr;
	oc  = v_minus(o, &oc);
	val.a = v_dot_prd(d, d);
	val.b = 2 * v_dot_prd(&oc, d);
	val.c = v_dot_prd(&oc, &oc) - pow(r, 2);
	discrim = pow(val.b, 2) - (4 * val.a * val.c);
	if (discrim < 0)
		return (hits);
	hits.t1 = (-val.b + sqrt(discrim)) / (2 * val.a);
	hits.t2 = (-val.b - sqrt(discrim)) / (2 * val.a);
	return (hits);
}

t_hs	spot_intersection(t_vector *o, t_vector *d, const void *obj)
{
	double		r;
	t_vector	oc;
	t_values	val;
	t_hs		hits;
	double		discrim;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	r = 0;
	oc = ((t_spot*)(obj))->position;
	oc  = v_minus(o, &oc);
	val.a = v_dot_prd(d, d);
	val.b = 2 * v_dot_prd(&oc, d);
	val.c = v_dot_prd(&oc, &oc) - pow(r, 2);
	discrim = pow(val.b, 2) - (4 * val.a * val.c);
	if (discrim < 0)
		return (hits);
	hits.t1 = (-val.b + sqrt(discrim)) / (2 * val.a);
	hits.t2 = (-val.b - sqrt(discrim)) / (2 * val.a);
	return (hits);
}