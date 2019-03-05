/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:08:59 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/16 18:21:16 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	reflection_ray(const t_vector *drct, const t_vector *nrm)
{
	t_vector	refl_drct;
	double		mult;

	mult = v_dot_prd(nrm, drct) * 2;
	refl_drct = v_mult_n(nrm, mult);
	refl_drct = v_minus(&refl_drct, drct);
	return (refl_drct);
}