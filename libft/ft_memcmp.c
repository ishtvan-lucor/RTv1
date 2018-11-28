/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:20:22 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:53:08 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	while (n != 0 && *temp1 == *temp2)
	{
		temp1++;
		temp2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((int)(*temp1 - *temp2));
}
