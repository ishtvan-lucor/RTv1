/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:46:41 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/16 20:28:32 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*bigstr;
	char	*str1;
	char	*str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (str2);
	if (s2 == NULL)
		return (str1);
	if ((bigstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (bigstr);
	ft_strcpy(bigstr, s1);
	ft_strcat(bigstr, s2);
	return (bigstr);
}
