/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:54:58 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/14 13:57:56 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	index;

	index = 0;
	if (!s)
		return ;
	if (fd == -1)
		ft_putstr("open error\n");
	else
		while (s[index] != '\0')
			ft_putchar_fd(s[index++], fd);
}
