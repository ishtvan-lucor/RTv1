/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:22:10 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/08 21:23:36 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

void	render(t_basic *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_H)
	{
		while(x < WIN_H)
		{
			s->img[x + y * WIN_W] =
			x++;
		}
		y++;
	}
}
// TODO write render universal there. render of sphere in other file