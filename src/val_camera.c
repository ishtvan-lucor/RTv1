/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 20:22:32 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/02 19:51:00 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

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

static int	get_rot(char *line, int *rot_x, int *rot_y)
{
	char	**s;
	int		error;
	size_t	len;

	len = ft_wordssplit(line, ' ');
	if (!(s = ft_strsplit(line, ' ')))
		return (ft_putstr("ERROR: to big string=)\n"));
	if (!ft_strcmp(s[0], ROT_X))
		error = val_int_cord(s, rot_x, len);
	else if (!ft_strcmp(s[0], ROT_Y))
		error = val_int_cord(s, rot_y, len);
	else
		error = ft_putstr("ERROR: invalid rotation of camera! MAN_CONF\n");
	return (error);
}

int			val_camera(int fd, t_vector *cmr, int *rot_x, int *rot_y)
{
	char	*line;
	int		res;

	*rot_x = 0;
	*rot_y = 0;
	res = 0;
	if (get_next_line(fd, &line) == 1 && !(res = get_points(line, cmr)))
	{
		free(line);
		while (get_next_line(fd, &line) == 1)
		{
			if (!ft_strcmp(line, DELIMITR))
				break ;
			if ((res = get_rot(line, rot_x, rot_y)))
				break ;
			free(line);
		}
		free(line);
		return (res);
	}
	if (!res)
		return (ft_putstr("ERROR: problem with reading config file!\n"));
	return (res);
}
