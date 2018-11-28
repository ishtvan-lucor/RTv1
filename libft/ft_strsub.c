/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:10:42 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:13:42 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	if (s == NULL)
		return (NULL);
	if ((ss = ft_strnew(len)) == NULL)
		return (ss);
	ss = ft_strncpy(ss, (s + start), len);
	return (ss);
}
