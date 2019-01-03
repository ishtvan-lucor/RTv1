/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:12:02 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/12/26 17:07:25 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

static void	preperation_and_start(char *config)
{
	t_basic sv;

	if (validation_config(config, &sv))
		return ;
	if (init_mlx(&sv))
		return ;
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

