/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:33:40 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:12:40 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && n != 0)
	{
		if (*s1++ != *s2++)
			return (0);
		n--;
	}
	if (*s1 != *s2 && n != 0)
		return (0);
	return (1);
}
