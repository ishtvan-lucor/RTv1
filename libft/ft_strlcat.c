/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 22:04:19 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:11:04 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t	len;
	size_t	len_dst;
	size_t	index;
	size_t	size;

	len = 0;
	index = 0;
	while (len < dstsize && dst[len] != '\0')
		len++;
	len_dst = len;
	size = dstsize - len;
	if (size == 0)
		return (ft_strlen(src) + len);
	while (src[index] != '\0')
	{
		if (size != 1)
		{
			dst[len] = src[index];
			len++;
			size--;
		}
		index++;
	}
	dst[len] = '\0';
	return (index + len_dst);
}
