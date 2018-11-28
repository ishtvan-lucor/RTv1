/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:18:05 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/15 12:24:52 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *lst1, t_list *lst2)
{
	t_list	*temp;

	if (lst1 == NULL || lst2 == NULL)
		return ;
	temp = lst1;
	lst1 = lst2;
	lst2 = temp;
}
