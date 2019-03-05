/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:37:37 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/03 21:20:53 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int	calc_clr(int cur_col, double comp)
{
	t_color	res;

	res = (t_color)cur_col;
	res.clr[RED] = (UC)round((double)res.clr[RED] * comp);
	res.clr[GREEN] = (UC)round((double)res.clr[GREEN] * comp);
	res.clr[BLUE] = (UC)round((double)res.clr[BLUE] * comp);
	return (res.color);
}

static void	normalize(t_co *data, t_vector *o, t_vector *d)
{
	if (data->type == PLANE)
		nrm_plane(data, d);
	else if (data->type == SPHERE)
		nrm_sphere(data);
	else if (data->type == CYLINDER)
		nrm_cylinder(data, d, o);
	else if (data->type == CONE)
		nrm_cone(data, d, o);
}

static void	calc_data_cl_obj(t_co *clst_obj, t_data_tr *data,
	const t_list *light, const t_list *prim)
{
	t_vector	temp;
	double		col_modif;

	temp = v_mult_n(&data->direction, clst_obj->t);
	clst_obj->hit = v_plus(&data->start, &temp);
	normalize(clst_obj, &data->start, &data->direction);
	clst_obj->color = ((t_aprm*)(clst_obj->obj))->clr.color;
	clst_obj->spcl = ((t_aprm*)(clst_obj->obj))->spcl;
	clst_obj->rfl = ((t_aprm*)(clst_obj->obj))->rfl;
	clst_obj->rvrs_drct = v_mult_n(&data->direction, -1);
	col_modif = calc_intensity(clst_obj, data, light, prim);
	clst_obj->color = calc_clr(clst_obj->color, col_modif);
}

int			trace_ray(t_data_tr *data, const t_list *obj,
	const t_list *light, int depth)
{
	t_co	clst_obj;
	int		ref_clr;

	get_closest_object(&clst_obj, data, obj);
	if (clst_obj.obj == NULL)
		return (BACKGROUND_COLOR);
	calc_data_cl_obj(&clst_obj, data, light, obj);
	if (depth == 0 || clst_obj.rfl <= 0.0)
		return (clst_obj.color);
	data->start = clst_obj.hit;
	data->direction = reflection_ray(&clst_obj.rvrs_drct, &clst_obj.nrm);
	data->min = START_NEAR_SURFACE;
	data->max = INFINITY_RAY_DIST;
	ref_clr = trace_ray(data, obj, light, (depth - 1));
	clst_obj.color = calc_clr(clst_obj.color, (1 - clst_obj.rfl));
	ref_clr = calc_clr(ref_clr, clst_obj.rfl);
	return (clst_obj.color + ref_clr);
}
