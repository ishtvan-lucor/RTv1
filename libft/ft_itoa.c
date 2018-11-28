/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:37:14 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:01:27 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	index;

	index = ft_intlen(n);
	if (!(str = ft_strnew(index)))
		return (str);
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str[0] = '-';
	else
		n *= -1;
	while (n < 0)
	{
		str[--index] = -(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
