/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:22:10 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/02 21:21:10 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_vector	point_from_screen_to_viewport(int x, int y)
{
	t_vector	temp;

	temp.x = FOV * ((double)x / WIN_W - 0.5);
	temp.y = FOV * (0.5 - (double)y / WIN_H);
	temp.z = FOV;
	return (temp);
}

static t_vector	rotation_x(t_vector *vec, double angle)
{
	t_vector	res;

	angle = (angle * M_PI / 180.0);
	res.x = vec->x;
	res.y = vec->y * cos(angle) + vec->z * sin(angle);
	res.z = -vec->y * sin(angle) + vec->z * cos(angle);
	return (res);
}

static t_vector	rotation_y(t_vector *vec, double angle)
{
	t_vector	res;

	angle = (angle * M_PI / 180.0);
	res.x = vec->x * cos(angle) + vec->z * sin(angle);
	res.y = vec->y;
	res.z = -vec->x * sin(angle) + vec->z * cos(angle);
	return (res);
}

static void	set_direction_cmr(int x, int y, t_data_tr *dtr, t_basic *s)
{
	t_vector	direction;

	dtr->start = s->cmr;
	direction = point_from_screen_to_viewport(x, y);
	direction = rotation_x(&direction, (double)s->rot_x);
	direction = rotation_y(&direction, (double)s->rot_y);
	dtr->direction = v_nrm(&direction);
}

void			render(t_basic *s)
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
			set_direction_cmr(x, y, &dtr, s);
			s->img[x + y * WIN_W] = trace_ray(&dtr, s->prim, s->light, DEPTH);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->p_to_img, 0, 0);
}
