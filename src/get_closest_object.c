/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:11:41 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/17 19:39:26 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_t(double cur_t, double min, double max, double *closest)
{
	if (cur_t >= min && cur_t <= max && cur_t < *closest)
	{
		*closest = cur_t;
		return (1);
	}
	return (0);
}

static t_hs	check_intersection(t_vector *o, t_vector *d, const t_list *obj)
{
	t_hs	hits;

	hits.t1 = INFINITY_RAY_DIST;
	hits.t2 = INFINITY_RAY_DIST;
	if (obj->content_size == SPHERE)
		hits = sphere_intersection(o, d, obj->content);
	return (hits);
}

void		get_closest_object(t_co *obj, t_data_tr *data, const t_list *entity)
{
	t_hs	hits;
	t_list	*temp;

	temp = (t_list*)entity;
	obj->obj = NULL;
	obj->t = INFINITY_RAY_DIST;
	while (temp)
	{
		hits = check_intersection(&data->start, &data->direction, temp);
		if (check_t(hits.t1, data->min, data->max, &obj->t))
			obj->obj = temp->content;
		if (check_t(hits.t2, data->min, data->max, &obj->t))
			obj->obj = temp->content;
		temp = temp->next;
	}
}

//TODO optimization a lot