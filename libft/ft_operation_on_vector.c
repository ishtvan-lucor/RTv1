/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_on_vector.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:19:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/07 20:42:28 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		v_prd(const t_vector *v1, const t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double		v_len(const t_vector *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

double		v_dot(const t_vector *vec)
{
	double	len_vec;

	len_vec = v_len(vec);
	return (len_vec * len_vec);
}

t_vector	*v_nrm(const t_vector *v)
{
	double		len;
	t_vector	*nrm;

	len = v_len(v);
	nrm = (t_vector*)malloc(sizeof(t_vector));
	*nrm = v_div_n(v, len);
	return (nrm);
}


//TODO check on right work of vector operation func