/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:50:47 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/04/15 16:57:33 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(fresh = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	fresh = f(lst);
	temp = fresh;
	while ((lst = lst->next) != NULL)
	{
		if ((temp->next = f(lst)) == NULL)
		{
			free(temp->next);
			return (NULL);
		}
		temp = temp->next;
	}
	return (fresh);
}
