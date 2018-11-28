/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:46:34 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/01 14:07:48 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	*last;

	temp = (char*)s;
	last = NULL;
	while (*temp != '\0')
	{
		if (*temp == (char)c)
			last = temp;
		temp++;
	}
	if (*temp == (char)c)
		return (temp);
	return (last);
}
