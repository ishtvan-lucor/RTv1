/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:50:47 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/03 18:09:18 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_hs	sphere_intersection(t_vector *o, t_vector *d, const void *obj)
{
	t_vector	oc;
	t_values	val;
	t_hs		hits;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	oc  = v_minus(o, &((t_sphere*)(obj))->cntr);
	val.a = v_dot_prd(d, d);
	val.b = 2 * v_dot_prd(&oc, d);
	val.c = v_dot_prd(&oc, &oc) - pow(((t_sphere*)(obj))->rds, 2);
	val.dscr = pow(val.b, 2) - (4 * val.a * val.c);
	if (val.dscr < 0)
		return (hits);
	hits.t1 = (-val.b + sqrt(val.dscr)) / (2 * val.a);
	hits.t2 = (-val.b - sqrt(val.dscr)) / (2 * val.a);
	return (hits);
}

t_hs	plane_intersection(t_vector *o, t_vector *d, const void *obj)
{
	t_hs		hits;
	t_vector	oc;
	double		dot_dv;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	dot_dv = v_dot_prd(d, &((t_plane*)(obj))->nrm);
	if (dot_dv == 0.0)
		return (hits);
	oc = v_minus(o, &((t_plane*)(obj))->point);
	oc = v_mult_n(&oc, -1);
	hits.t1 = v_dot_prd(&oc, &((t_plane*)(obj))->nrm) / dot_dv;
	return (hits);
}

t_hs	cylinder_intersection(t_vector *o, t_vector *d, const void *obj)
{
	double		v[2];
	t_hs		hits;
	t_values	val;
	t_vector	oc;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	oc = v_minus(o, &((t_cylinder*)(obj))->start);
	v[DOT_XV] = v_dot_prd(&oc, &((t_cylinder*)(obj))->axis);
	v[DOT_DV] = v_dot_prd(d, &((t_cylinder*)(obj))->axis);
	val.a = v_dot_prd(d, d) - pow(v[DOT_DV], 2);
	val.b = 2 * (v_dot_prd(d, &oc) - v[DOT_DV] * v[DOT_XV]);
	val.c = v_dot_prd(&oc, &oc) - pow(v[DOT_XV], 2) -
		pow(((t_cylinder*)obj)->rds, 2);
	val.dscr = pow(val.b, 2) - (4 * val.a * val.c);
	if (val.dscr < 0)
		return (hits);
	hits.t1 = (-val.b + sqrt(val.dscr)) / (2 * val.a);
	hits.t2 = (-val.b - sqrt(val.dscr)) / (2 * val.a);
	return (hits);
}

t_hs	cone_intersection(t_vector *o, t_vector *d, const void *obj)
{
	double		v[3];
	t_hs		hits;
	t_values	val;
	t_vector	oc;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	oc = v_minus(o, &((t_cone*)(obj))->start);
	v[DOT_XV] = v_dot_prd(&oc, &((t_cone*)(obj))->axis);
	v[DOT_DV] = v_dot_prd(d, &((t_cone*)(obj))->axis);
	v[KK1] = 1 + pow(((t_cone*)(obj))->angle, 2);
	val.a = v_dot_prd(d, d) - v[KK1] * pow(v[DOT_DV], 2);
	val.b = 2 * (v_dot_prd(d, &oc) - v[KK1] * v[DOT_DV] * v[DOT_XV]);
	val.c = v_dot_prd(&oc, &oc) - v[KK1] * pow(v[DOT_XV], 2);
	val.dscr = pow(val.b, 2) - (4 * val.a * val.c);
	if (val.dscr < 0)
		return (hits);
	hits.t1 = (-val.b + sqrt(val.dscr)) / (2 * val.a);
	hits.t2 = (-val.b - sqrt(val.dscr)) / (2 * val.a);
	return (hits);
}
