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
		return (0);
	if (*s == '0')
		s++;
	if (*s == 'x' || *s == 'X')
		s++;
	if (!(*s))
		return (0);
	while (*s && len-- > 0)
	{
		if (ft_isdigit((int)(*s)) || (*s >= 'A' && *s <= 'F') ||
				(*s >= 'a' && *s <= 'f'))
			s++;
		else
			return (0);
	}
	if (*s)
		return (0);
	return (1);
}
