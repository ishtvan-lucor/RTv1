/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscolor_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:40:43 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/06/28 17:23:22 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iscolor_rgb(const char *s)
{
	size_t	len;

	len = 6;
	if (!s)
		return (1);
	if (*s == '0')
		s++;
	if (*s == 'x' || *s == 'X')
		s++;
	if (!(*s))
		return (1);
	while (*s && len-- > 0)
	{
		if (ft_isdigit((int)(*s)) || (*s >= 'A' && *s <= 'F') ||
				(*s >= 'a' && *s <= 'f'))
			s++;
		else
			return (1);
	}
	if (*s)
		return (1);
	return (0);
}
