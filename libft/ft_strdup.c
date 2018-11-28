/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:24:06 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/03 15:46:40 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1);
	if ((new = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	new = ft_memcpy(new, s1, (len));
	new[len] = '\0';
	return (new);
}
