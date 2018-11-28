/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 20:52:34 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/11 20:57:51 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(char const *s, size_t start, char const c)
{
	size_t	len;

	len = 0;
	while (s[start] != c && s[start++] != '\0')
		len++;
	return (len);
}
