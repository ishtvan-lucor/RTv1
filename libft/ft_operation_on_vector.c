/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:19:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/10 21:20:34 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	ft_len_vector(const t_vector vec)
{
	return (sqrt(vec.x *vec.x + vec.y * vec.y + vec.z * vec.z));
}