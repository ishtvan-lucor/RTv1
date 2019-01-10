/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_on_vector.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:19:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/10 21:32:41 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_len_vector(const t_vector vec)
{
	return (sqrt(vec.x *vec.x + vec.y * vec.y + vec.z * vec.z));
}

double	ft_dot_vector(const t_vector vec)
{
	double	len_vec;

	len_vec = ft_len_vector(vec);
	return (vec * vec);
}


// TODO write another useful vec operation like nrm, prodact -- check else
// TODO check that they work properly