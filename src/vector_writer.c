/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:16:33 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/05 17:27:15 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	vector_writer(char *c1, char *c2, char *c3, t_vector *t)
{
	if (!c1 || !ft_isdouble_or_int(c1))
		return (ft_putstr("ERROR: first coordinate invalid!\n"));
	if (!c2 || !ft_isdouble_or_int(c2))
		return (ft_putstr("ERROR: second coordinate invalid!\n"));
	if (!c3 || !ft_isdouble_or_int(c3))
		return (ft_putstr("ERROR: third coordinate invalid!\n"));
	t->x = ft_string_to_double(c1);
	t->y = ft_string_to_double(c2);
	t->z = ft_string_to_double(c3);
	return (0);
}