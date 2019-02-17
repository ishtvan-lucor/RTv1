/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:11:41 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/17 14:39:48 by ikoloshy         ###   ########.fr       */
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

void		get_closest_object(t_co *obj, t_data_tr *data, const t_list *entity)
{
	t_hs	hits;

	obj->obj = NULL;
	obj->t = INFINITY_RAY_DIST;
	while (entity)
	{
		hits = g_intersection[entity->content_size](&data->start,
			&data->direction, &entity->content);
		if (check_t(hits.t1, data->min, data->max, &obj->t))
			obj->obj = entity->content;
		if (check_t(hits.t2, data->min, data->max, &obj->t))
			obj->obj = entity->content;
		entity = entity->next;
	}
}