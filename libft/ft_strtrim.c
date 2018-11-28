/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:14:39 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:21:22 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	unsigned int	index;

	if (!s)
		return (NULL);
	index = 0;
	len = ft_strlen(s) - 1;
	while (s[index] == ' ' || s[index] == '\t' || s[index] == '\n')
		index++;
	if (index == (len + 1))
		return (ft_strnew(0));
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	return (ft_strsub(s, index, (len - (size_t)index + 1)));
}
