/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_on_vector.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:19:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/13 18:04:27 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	v_prd(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	v_len(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

double	v_dot(t_vector vec)
{
	double	len_vec;

	len_vec = v_len(vec);
	return (len_vec * len_vec);
}

double v_nrm(t_vector v)
{
	return (v/(sqrt(v.x *v.x + v.y * v.y + v.z * v.z)));
}

// TODO check that they work properly