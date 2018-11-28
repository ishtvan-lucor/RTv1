/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:57:58 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/01 19:23:01 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*temp;

	temp = (char*)haystack;
	if (*needle == '\0')
		return (temp);
	while (*temp != '\0')
	{
		temp = ft_strchr(temp, (int)*needle);
		if (temp == NULL)
			break ;
		if (ft_strncmp(temp, needle, ft_strlen(needle)) == 0)
			return (temp);
		temp++;
	}
	return (NULL);
}
