/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:12:02 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/09 16:44:42 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	error_free(t_list *prim, t_list *light)
{
	while (prim)
	{
		free(prim->content);
		free(prim);
		prim = prim->next;
	}
	while (light)
	{
		free(light->content);
		free(light);
		light = light->next;
	}
}

static void	preparation_and_start(char *config)
{
	t_basic sv;

	sv.prim = NULL;
	sv.light = NULL;
	if (validation_config(config, &sv))
	{
		error_free(sv.prim, sv.light);
		return ;
	}
	if (analyze_light(sv.light) || analyze_prim(sv.prim))
	{
		error_free(sv.prim, sv.light);
		return ;
	}
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
		preparation_and_start(argv[1]);
	else
		ft_putstr("ERROR: too mach arguments! Usage: ./RTv1 config_file");
	return (0);
}
