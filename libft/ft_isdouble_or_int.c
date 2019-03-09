/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble_or_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:50:17 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/03 18:09:12 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdouble_or_int(const char *str)
{
	int dot;

	dot = 1;
	if (*str == '.')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (*(str + 1) == '\0')
				return (0);
			dot++;
		}
		else if (!ft_isdigit((int)(*str)) || dot > 2)
			return (0);
		str++;
	}
	return (dot);
}
