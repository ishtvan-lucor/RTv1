/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_loop_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:07:34 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/07 17:50:06 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int	catch_esc(int key, t_basic *storage)
{
	if (key == 53)
	{
		mlx_destroy_image(storage->mlx, storage->p_to_img);
		mlx_destroy_window(storage->mlx, storage->win);
		exit(0);
	}
	return (0);
}

static int	exit_x(t_basic *s) {
	mlx_destroy_image(s->mlx, s->p_to_img);
	mlx_destroy_window(s->mlx, s->win);
	exit(0);
}

void		start_loop_mlx(t_basic *storage)
{
	mlx_hook(storage->win, 2, 5, catch_esc, storage);
	mlx_hook(storage->win, 17, 1L << 17, exit_x, storage);
	mlx_loop(storage->mlx);
}
