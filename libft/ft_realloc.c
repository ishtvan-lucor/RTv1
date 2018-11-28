/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:31:23 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/15 12:41:08 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t old_size, size_t new_size)
{
	void	*temp;

	if (!src)
		return (NULL);
	if (!(temp = ft_memalloc(new_size)))
		return (NULL);
	if (old_size < new_size)
		ft_memcpy(temp, src, old_size);
	else
		ft_memcpy(temp, src, new_size);
	free(src);
	return (temp);
}
