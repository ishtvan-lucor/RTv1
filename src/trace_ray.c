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

int				trace_ray(t_data_tr *d, const t_list *obj, const t_list *light)
{
	t_co	clst_obj;

	clst_obj.obj = NULL;
	get_closest_object(&clst_obj, d);
	if (clst_obj.obj == NULL)
		return (BACKGROUND_COLOR);

}

// TODO after making universal struct