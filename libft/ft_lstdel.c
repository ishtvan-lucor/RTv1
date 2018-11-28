/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:20:25 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/15 14:44:32 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst == NULL || *alst == NULL)
		return ;
	while (*alst != NULL)
	{
		temp = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = temp;
	}
	*alst = NULL;
}
