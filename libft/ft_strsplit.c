/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:56:46 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 18:17:25 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	words;
	size_t	si;
	size_t	index;

	si = 0;
	index = 0;
	if (!s)
		return (NULL);
	words = ft_wordssplit(s, c);
	if (!(str = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
		return (str);
	while (index < words)
	{
		while (s[si] == c)
			si++;
		str[index] = ft_strsub(s, (unsigned int)si, ft_strclen(s, si, c));
		if (str[index] == NULL)
			return (NULL);
		si = si + ft_strclen(s, si, c);
		index++;
	}
	str[words] = 0;
	return (str);
}
