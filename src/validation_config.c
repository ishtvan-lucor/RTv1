/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_config.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:58:34 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/17 15:48:04 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_light(int fd, int obj, t_list **light)
{
	if (obj == SPOT)
		return (val_spot(fd, light));
	return (0);
}

static int	check_prim(int fd, int obj, t_list **prim)
{
	if (obj == SPHERE)
		return (val_sphere(fd, prim));
	return (0);
}

//TODO add new primitives and lights

static int	define_obj(char *line)
{
	if (!ft_strcmp(line, "sphere"))
		return (SPHERE);
	else if (!ft_strcmp(line, "spot"))
		return (SPOT);
	else
		return (-1);
}

static int	find_objects(int fd, t_list **light, t_list **prim)
{
	char	*line;
	int		obj;
	int		error;

	while (get_next_line(fd, &line) == 1)
	{
		obj = define_obj(line);
		if (obj == -1)
			error = ft_putstr("ERROR: invalid object name! MAN_CONF");
		else if (obj > CYLINDER)
			error = check_light(fd, obj, light);
		else
			error = check_prim(fd, obj, prim);
		free(line);
		if (error)
			return (1);
	}
	return (0);
}

int			validation_config(char *config, t_basic *sv)
{
	int		fd;

	if ((fd = open(config, O_RDONLY)) == -1)
		return (ft_putstr("ERROR: fail read!\n"));
	if (val_camera(fd, &sv->cmr))
		return (ft_putstr("ERROR: incorrect camera data! MAN_CONF\n"));
	if (find_objects(fd, &sv->light, &sv->prim))
		return (1);
	if (close(fd) == -1)
		return (ft_putstr("ERROR: fail close!\n"));
	return (0);
}

// TODO if rewrite parsing read about ini file
//todo MAN_CONF
