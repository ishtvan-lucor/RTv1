/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:37:37 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/12 21:16:31 by ikoloshy         ###   ########.fr       */
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

static void	calculete_data_cl_obj(t_co *clst_obj, t_vector *d, t_vector *o)
{
	t_vector	temp;
	double		col_modif;

	temp = v_mult_n(d, clst_obj->t);
	clst_obj->hit =v_plus(o, &temp);
	//TODO normalize vector
	clst_obj->color = ((t_aprm*)(clst_obj->obj))->clr.color;
	clst_obj->spcl = ((t_aprm*)(clst_obj->obj))->spcl;
	clst_obj->rfl = ((t_aprm*)(clst_obj->obj))->rfl;
	temp = v_mult_n(d, -1);
	//TODO write culc_light
	col_modif = culc_light(clst_obj->hit, clst_obj->nrm, temp, clst_obj->spcl);
	clst_obj->color = culc_clr(clst_obj->color, col_modif);
}

int			trace_ray(t_data_tr *d, const t_list *obj, const t_list *light, int depth)
{
	t_co	clst_obj;
	int		ref_clr;

	clst_obj.obj = NULL;
	//TODO write get_closet_obj
	get_closest_object(&clst_obj, d);
	if (clst_obj.obj == NULL)
		return (BACKGROUND_COLOR);
	calculete_data_cl_obj(&clst_obj, &d->direction, &d->start);
	if (depth == 0 || clst_obj.rfl <= 0.0)
		return clst_obj.color;
	//TODO ReflectedRay function global
	d->start = clst_obj.hit;
	d->direction = reflection_ray(v_mult_n(&d->direction, -1), clst_obj.nrm);
	d->min = 0.001;
	ref_clr = trace_ray(d, obj, light, (depth - 1));
	clst_obj.color = culc_clr(clst_obj.color, (1 - clst_obj.rfl));
	ref_clr = culc_clr(ref_clr, clst_obj.rfl);
	return (clst_obj.color + ref_clr);
}



