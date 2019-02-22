/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:50:47 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/22 14:33:22 by ikoloshy         ###   ########.fr       */
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

t_hs	plane_intersection(t_vector *o, t_vector *d, const void *obj)
{
	t_hs		hits;
	t_vector	oc;
	double	dot_dv;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	dot_dv = v_dot_prd(d, &((t_plane*)(obj))->nrm);
	if (dot_dv == 0.0)
		return (hits);
	oc = ((t_plane*)(obj))->point;
	oc = v_minus(o, &oc);
	oc = v_mult_n(&oc, -1);
	hits.t1 = v_dot_prd(&oc, &((t_plane*)(obj))->nrm) / dot_dv;
	return (hits);
}

t_hs	cylinder_intersection(t_vector *o, t_vector *d, const void *obj)
{
	t_hs		hits;
	double		dot_dv;
	double		dot_xv;
	t_values	val;
	t_vector	x;
	double		discrim;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	x = v_minus(o, &((t_cylinder*)(obj))->start);
	dot_xv = v_dot_prd(&x, &((t_cylinder*)(obj))->axis);
	dot_dv = v_dot_prd(d, &((t_cylinder*)(obj))->axis);
	val.a = v_dot_prd(d, d) - pow(dot_dv, 2);
	val.b = 2 * (v_dot_prd(d, &x) - dot_dv * dot_xv);
	val.c = v_dot_prd(&x, &x) - pow(dot_xv, 2) - pow(((t_cylinder*)(obj))->rds, 2);
	discrim = pow(val.b, 2) - (4 * val.a * val.c);
	if (discrim < 0)
		return (hits);
	hits.t1 = (-val.b + sqrt(discrim)) / (2 * val.a);
	hits.t2 = (-val.b - sqrt(discrim)) / (2 * val.a);
	return (hits);
}

t_hs	cone_intersection(t_vector *o, t_vector *d, const void *obj)
{
	t_hs		hits;
	double		dot_dv;
	double		dot_xv;
	t_values	val;
	t_vector	x;
	double		discrim;
	double		kk1;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	x = v_minus(o, &((t_cone*)(obj))->start);
	dot_xv = v_dot_prd(&x, &((t_cone*)(obj))->axis);
	dot_dv = v_dot_prd(d, &((t_cone*)(obj))->axis);
	kk1 = 1 + pow(((t_cone*)(obj))->angle, 2);
	val.a = v_dot_prd(d, d) - kk1 * pow(dot_dv, 2);
	val.b = 2 * (v_dot_prd(d, &x) - kk1 * dot_dv * dot_xv);
	val.c = v_dot_prd(&x, &x) - kk1 * pow(dot_xv, 2);
	discrim = pow(val.b, 2) - (4 * val.a * val.c);
	if (discrim < 0)
		return (hits);
	hits.t1 = (-val.b + sqrt(discrim)) / (2 * val.a);
	hits.t2 = (-val.b - sqrt(discrim)) / (2 * val.a);
	return (hits);
}

//TODO optimization