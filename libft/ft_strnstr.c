/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:35:30 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:18:33 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hs;
	char	*nd;

	hs = (char*)haystack;
	nd = (char*)needle;
	if (*nd == '\0')
		return (hs);
	while (*hs != '\0' && len != 0)
	{
		if (*hs == *nd)
			if (ft_strlen(nd) > len)
				return (NULL);
		if (ft_strncmp(hs, nd, ft_strlen(nd)) == 0)
			return (hs);
		hs++;
		len--;
	}
	return (NULL);
}
