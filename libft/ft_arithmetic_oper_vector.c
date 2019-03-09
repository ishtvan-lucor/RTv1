/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arithmetic_oper_vector.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 19:04:51 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/07 19:04:51 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	v_plus(const t_vector *v1, const t_vector *v2)
{
	t_vector	res;

	res.x = v1->x + v2->x;
	res.y = v1->y + v2->y;
	res.z = v1->z + v2->z;
	return (res);
}

t_vector	v_minus(const t_vector *v1, const t_vector *v2)
{
	t_vector	res;

	res.x = v1->x - v2->x;
	res.y = v1->y - v2->y;
	res.z = v1->z - v2->z;
	return (res);
}

t_vector	v_mult(const t_vector *v1, const t_vector *v2)
{
	t_vector	res;

	res.x = v1->x * v2->x;
	res.y = v1->y * v2->y;
	res.z = v1->z * v2->z;
	return (res);
}

t_vector	v_div(const t_vector *v1, const t_vector *v2)
{
	t_vector	res;

	res.x = v1->x / v2->x;
	res.y = v1->y / v2->y;
	res.z = v1->z / v2->z;
	return (res);
}
