/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:12:02 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/12/15 15:05:54 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

int		exit_x(t_basic *s) {
	s = NULL;
	exit(1);
}

void	preperation_for_start(char *config)
{
	t_basic sv;
	if (validation_config(config))
		return ;
	if (!(sv.mlx = mlx_init()))
		ft_putstr("ERROR: failed initialization!");
	else if (!(sv.win = mlx_new_window(sv.mlx, WIN_W, WIN_H, "RTv1")))
		ft_putstr("ERROR: failed creation of window!");
	mlx_hook(sv.win, 17, 1L << 17, exit_x, &sv);
	mlx_loop(sv.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("ERROR: no configuration file! Usage: ./RTv1 config_file");
	else if (argc == 2)
		preperation_for_start(argv[1]);
	else
		ft_putstr("ERROR: too mach arguments! Usage: ./RTv1 config_file");
	return (0);
}

