/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:37:37 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/22 21:23:50 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	culc_clr(int cur_col, double comp)
{
	t_color	res;

	res = (t_color)cur_col;
	res.clr[RED] = (UC)round((double)res.clr[RED] * comp);
	res.clr[GREEN] = (UC)round((double)res.clr[GREEN] * comp);
	res.clr[BLUE] = (UC)round((double)res.clr[BLUE] * comp);
	return	(res.color);
}

static void	normalize(t_co *data, t_vector *o, t_vector *d)
{
	if (data->type == PLANE)
		normalize_plane(data, o, d);
	else if (data->type == SPHERE)
		normalize_sphere(data, o, d);
	else if (data->type == CYLINDER)
		normalize_cylinder(data, o, d);
	else if (data->type == CONE)
		normalize_cone(data, o, d);
}

static void	calc_data_cl_obj(t_co *clst_obj, t_vector *d, t_vector *o,
	const t_list *light, const t_list *prim)
{
	t_vector	temp;
	double		col_modif;

	temp = v_mult_n(d, clst_obj->t);
	clst_obj->hit =v_plus(o, &temp);

	//TODO normalize for all universal
	clst_obj->nrm = ((t_sphere*)(clst_obj->obj))->cntr;
	clst_obj->nrm = v_minus(&clst_obj->hit, &clst_obj->nrm);
	clst_obj->nrm = v_nrm(&clst_obj->nrm);

	clst_obj->color = ((t_aprm*)(clst_obj->obj))->clr.color;
	clst_obj->spcl = ((t_aprm*)(clst_obj->obj))->spcl;
	clst_obj->rfl = ((t_aprm*)(clst_obj->obj))->rfl;
	clst_obj->rvrs_drct = v_mult_n(d, -1);
	col_modif = culc_intensity(clst_obj, light, prim);
	clst_obj->color = culc_clr(clst_obj->color, col_modif);
}

int			trace_ray(t_data_tr *d, const t_list *obj, const t_list *light, int depth)
{
	t_co	clst_obj;
	int		ref_clr;

	get_closest_object(&clst_obj, d, obj);
	if (clst_obj.obj == NULL)
		return (BACKGROUND_COLOR);
	calc_data_cl_obj(&clst_obj, &d->direction, &d->start, light, obj);
	if (depth == 0 || clst_obj.rfl <= 0.0)
		return clst_obj.color;
	// reflective!!!
	d->start = clst_obj.hit;
	d->direction = reflection_ray(&clst_obj.rvrs_drct, &clst_obj.nrm);
	d->min = START_NEAR_SURFACE;
	d->max = INFINITY_RAY_DIST;
	ref_clr = trace_ray(d, obj, light, (depth - 1));
	clst_obj.color = culc_clr(clst_obj.color, (1 - clst_obj.rfl));
	ref_clr = culc_clr(ref_clr, clst_obj.rfl);
	return (clst_obj.color + ref_clr);
}

//TODO optimization: use ones data struct t_data_tr

