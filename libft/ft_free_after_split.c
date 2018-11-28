/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_after_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 20:39:41 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/01 20:53:45 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_after_split(char **str, size_t len)
{
	size_t i;

	i = 0;
	if (!str || !(*str))
		return ;
	while (i <= len)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
