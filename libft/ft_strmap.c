/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:58:48 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:10:26 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	if (!(temp = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[index] != '\0')
	{
		temp[index] = (*f)(s[index]);
		index++;
	}
	return (temp);
}
