/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_data_obj_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:09:50 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/07 20:27:19 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	val_color(char **s, t_color *trg, size_t len)
{
	if (len != 2)
		return (ft_putstr("ERROR:{clr} invalid amount of data!\n"));
	if (ft_iscolor_rgb(s[1]))
		return (ft_putstr("ERROR: invalid color!\n"));
	trg->color = ft_atoi_base((s[1] + 2), 16);
	return (0);
}

/*
** Check line with type and double coordinate
*/

int	val_double_cord(char **s, double *trg, size_t len)
{
	int	type;

	if (len != 2)
		return (ft_putstr("ERROR:{dbl} invalid amount of data!\n"));
	if (!(type = ft_isdouble_or_int(s[1])))
		return (ft_putstr("ERROR: invalid value!\n"));
	*trg = ft_string_to_double(s[1]);
	return (0);
}

/*
** Check line with type and int coordinate
*/

int	val_int_cord(char **s, int *trg, size_t len)
{
	int	type;

	if (len != 2)
		return (ft_putstr("ERROR:{int} invalid amount of data!\n"));
	if (!(type = ft_isdouble_or_int(s[1])))
		return (ft_putstr("ERROR: invalid value!\n"));
	if (type == 1)
		*trg = ft_atoi(s[1]);
	else
		return (ft_putstr("ERROR: int coordinate expected there1"));
	return (0);
}

/*
** Check valid vector coordinate like: type x y z
*/

int	val_vector(char **s, t_vector *trg, size_t len)
{
	int		error_code;

	if (len != 4)
		return (ft_putstr("ERROR:{vctr} invalid amount of data!\n"));
	error_code = vector_writer(s[1], s[2], s[3], trg);
	return (error_code);
}