/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:12:02 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/28 17:27:17 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	preperation_and_start(char *config)
{
	t_basic sv;

	sv.prim = NULL;
	sv.light = NULL;
	if (validation_config(config, &sv))
		return ;
	if (analyze_light(sv.light) || analyze_prim(sv.prim))
		return ;
	if (init_mlx(&sv))
		return ;
	render(&sv);
	start_loop_mlx(&sv);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("ERROR: no configuration file! Usage: ./RTv1 config_file");
	else if (argc == 2)
		preperation_and_start(argv[1]);
	else
		ft_putstr("ERROR: too mach arguments! Usage: ./RTv1 config_file");
	return (0);
}
