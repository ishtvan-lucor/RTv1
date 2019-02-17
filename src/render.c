/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:22:10 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/17 21:19:01 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	t_vector	point_from_screen_to_viewport(int x, int y)
{
	t_vector	temp;

	temp.x = FOV * ((double)x / WIN_W - 0.5);
	temp.y = FOV * (0.5 - (double)y / WIN_H);
	temp.z = FOV;
	return (temp);
}

void				render(t_basic *s)
{
	int			x;
	int			y;
	t_data_tr	dtr;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_H)
		{
			dtr.min = START_OF_VIEWPORT;
			dtr.max = INFINITY_RAY_DIST;
			dtr.direction = point_from_screen_to_viewport(x, y);
			dtr.start = s->cmr;
			s->img[x + y * WIN_W] = trace_ray(&dtr, s->prim, s->light, DEPTH);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->p_to_img, 0, 0);
}

// TODO check correctly work point_from_screen_to_viewport
// TODO add funct that make right angle for camera view