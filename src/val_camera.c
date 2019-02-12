/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:22:32 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/07 17:22:59 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_points(const char *line, t_vector *cmr)
{
	char	**s;
	size_t	len;
	int		error_f;

	if (!(s = ft_strsplit(line, ' ')))
		return (ft_putstr("ERROR: to big string=)\n"));
	if ((len = ft_wordssplit(line, ' ')) != 4)
	{
		ft_free_after_split(s, len);
		return (ft_putstr("ERROR: useless information is present 0_0\n"));
	}
	if (ft_strcmp(s[0], CMR))
	{
		ft_free_after_split(s, len);
		return (ft_putstr("ERROR: first line should be camera's position)\n"));
	}
	error_f = vector_writer(s[1], s[2], s[3], cmr);
	ft_free_after_split(s, len);
	return (error_f);
}

int			val_camera(int fd, t_vector *cmr)
{
	char	*line;
	int		res;

	if (get_next_line(fd, &line) != 1)
	{
		free(line);
		return (ft_putstr("ERROR: problem with reading config file!\n"));
	}
	res = get_points(line, cmr);
	free(line);
	get_next_line(fd, &line);
	if (ft_strcmp(line, DELIMITR))
		res = ft_putstr("ERROR: Wrong syntax! MAN_CONF\n");
	free(line);
	return (res);
}
