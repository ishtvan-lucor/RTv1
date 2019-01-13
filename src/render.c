/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:22:10 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/10 21:09:34 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

static int	get_color(t_vector d, t_vector cmr, t_list *obj, t_list *l)
{

}

void		render(t_basic *s)
{
	int			x;
	int			y;
	t_vector		d;

	x = 0;
	y = 0;
	while (y < WIN_H)
	{
		while(x < WIN_H)
		{
			d = point_from_screen_to_viewport(x, y);
			s->img[x + y * WIN_W] = get_color(d, s->cmr, s->prim, s->light);
			x++;
		}
		y++;
	}
}
// TODO write render universal there. render of sphere in other file