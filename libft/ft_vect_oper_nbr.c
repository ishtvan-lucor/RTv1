/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_oper_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:24:26 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/07 20:30:11 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	v_plus_n(const t_vector *vec, double nbr)
{
	t_vector	res;

	res.x = vec->x + nbr;
	res.y = vec->y + nbr;
	res.z = vec->z + nbr;
	return (res);
}

t_vector	v_minus_n(const t_vector *vec, double nbr)
{
	t_vector	res;

	res.x = vec->x - nbr;
	res.y = vec->y - nbr;
	res.z = vec->z - nbr;
	return (res);
}

t_vector	v_mult_n(const t_vector *vec, double nbr)
{
	t_vector	res;

	res.x = vec->x * nbr;
	res.y = vec->y * nbr;
	res.z = vec->z * nbr;
	return (res);
}

t_vector	v_div_n(const t_vector *vec, double nbr)
{
	t_vector	res;

	res.x = vec->x / nbr;
	res.y = vec->y / nbr;
	res.z = vec->z / nbr;
	return (res);
}
