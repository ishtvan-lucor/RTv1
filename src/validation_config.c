/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_config.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:58:34 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/03 21:21:34 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

int			validation_config(char *config, t_basic *sv)
{
	int		fd;

	if ((fd = open(config, O_RDONLY)) == -1)
		return (ft_putstr("ERROR: fail read!\n"));
	if (val_camera(fd, &sv->cmr))
		return (ft_putstr("ERROR: incorrect camera data! MAN_CONF\n"));
	if (close(fd) == -1)
		return (ft_putstr("ERROR: fail close!\n"));
	return (0);
}

//todo MAN_CONF
