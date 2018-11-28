/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 20:04:17 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/03/31 21:49:01 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	lens1;
	size_t	index;

	index = 0;
	lens1 = ft_strlen(s1);
	while (index < n && s2[index] != '\0')
	{
		s1[lens1 + index] = s2[index];
		index++;
	}
	s1[lens1 + index] = '\0';
	return (s1);
}
