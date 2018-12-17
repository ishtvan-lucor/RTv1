/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_loop_mlx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:43:41 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/12/17 18:44:32 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

int		catch_esc(int key, t_basic *storage)
{
	if (key == 53)
	{
		storage = NULL;
		exit(1);
	}
	return (0);
}

int		exit_x(t_basic *s) {
	s = NULL;
	exit(1);
}

void	loop_and_catch_exits(t_basic *storage)
{
	mlx_hook(storage->win, 2, 5, catch_esc, storage);
	mlx_hook(storage->win, 17, 1L << 17, exit_x, storage);
	mlx_loop(storage->mlx);
}

void	create_default_image(t_basic *store)
{
	t_is	im_spec;

	store->p_to_img = mlx_new_image(store->mlx, WIN_W, WIN_H);
	store->img = (int*)mlx_get_data_addr(store->p_to_img, &im_spec.bpp,
		&im_spec.sl, &im_spec.endl);
	store->spec = im_spec;
	ft_bzero(store->img, (WIN_W * WIN_H * 4));
}

int		init_mlx(t_basic *s)
{
	if (!(s->mlx = mlx_init()))
	{
		ft_putstr("ERROR: failed initialization!");
		return (1);
	}
	if (!(s->win = mlx_new_window(s->mlx, WIN_W, WIN_H, "RTv1")))
	{
		ft_putstr("ERROR: failed creation of window!");
		return (1);
	}
	create_default_image(s);
	return (0);
}