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
	//TODO understand abount accuracy of color
	clst_obj->color *= col_modif;
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
	calculete_data_cl_obj(&clst_obj, &d->d, &d->o);
	//TODO end trace_ray
}



