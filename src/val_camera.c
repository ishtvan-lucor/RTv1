/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:22:32 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/05 17:26:12 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

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
	if (ft_strcmp(s[0], "camera"))
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
	return (res);
}
