/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:09:58 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:06:22 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d == s)
		return (d);
	else if (d < s)
		while (len-- != 0)
			*d++ = *s++;
	else
	{
		d += len - 1;
		s += len - 1;
		while (len-- != 0)
			*d-- = *s--;
	}
	return (dst);
}
