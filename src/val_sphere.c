/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:49:50 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/07 20:42:40 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	find_data(char *line, t_sphere *sphere)
{
	char	**s;
	int		error_f;
	size_t	len;

	len = ft_wordssplit(line, ' ');
	if (!(s = ft_strsplit(line, ' ')))
		return (ft_putstr("ERROR: to big string=)\n"));
	if (!ft_strcmp(s[0], CNTR))
		error_f = val_vector(s, &sphere->cntr, len);
	else if (!ft_strcmp(s[0], RDS))
		error_f = val_double_cord(s, &sphere->rds, len);
	else if (!ft_strcmp(s[0], CLR))
		error_f = val_color(s, &sphere->clr, len);
	else if (!ft_strcmp(s[0], RFL))
		error_f = val_double_cord(s, &sphere->rfl, len);
	else if (!ft_strcmp(s[0], SPC))
		error_f = val_int_cord(s, &sphere->spcl, len);
	else
		error_f = ft_putstr("ERROR: invalid parameter of sphere! MAN_CONF\n");
	ft_free_after_split(s, len);
	return (error_f);
}

static int	read_line(int fd, t_sphere *s)
{
	char	*line;
	int		counter;

	counter = 0;
	while (get_next_line(fd, &line) == 1 && counter < 5)
	{
		if (!ft_strcmp(line, DELIMITR))
		{
			free(line);
			break;
		}
		if (find_data(line, s))
		{
			free(line);
			return (ft_putstr("ERROR: invalid sphere! MAN_CONF"));
		}
		free(line);
		counter++;
	}
	return (0);
}

//TODO need to check about all needed parameters are set

int			val_sphere(int fd, t_list **prim)
{
	t_sphere	*obj;
	t_list		*temp;

	obj = (t_sphere*)malloc(sizeof(t_sphere));
	ft_set_vector(&obj->cntr, 5, 5, 5);
	obj->rds = 1;
	obj->clr.color = 0xffffff;
	obj->spcl = SPECULAR;
	obj->rfl = REFLECTIVE;
	if (read_line(fd, obj))
		return (1);
	temp = ft_lstnew(obj, sizeof(t_sphere));
	temp->content_size = SPHERE;
	ft_lstadd(prim, temp);
	return (0);
}