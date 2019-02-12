/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:00:30 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/07 20:43:49 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	find_data(char *line, t_spot *spot)
{
	char	**s;
	int		error_f;
	size_t	len;

	len = ft_wordssplit(line, ' ');
	if (!(s = ft_strsplit(line, ' ')))
		return (ft_putstr("ERROR: to big string=)\n"));
	if (!ft_strcmp(s[0], INTN))
		error_f = val_double_cord(s, &spot->intensity, len);
	else if (!ft_strcmp(s[0], PSTN))
		error_f = val_vector(s, &spot->position, len);
	else
		error_f = ft_putstr("ERROR: invalid parameter of spot! MAN_CONF");
	ft_free_after_split(s, len);
	return (error_f);
}

static int	read_line(int fd, t_spot *s)
{
	char	*line;
	int		counter;

	counter = 0;
	while (get_next_line(fd, &line) == 1 && counter < 2)
	{
		if (!ft_strcmp(line, DELIMITR))
		{
			free(line);
			break;
		}
		if (find_data(line, s))
		{
			free(line);
			return (ft_putstr("ERROR: invalid light spot! MAN_CONF"));
		}
		free(line);
		counter++;
	}
	return (0);
}

int	val_spot(int fd, t_list **light)
{
	t_spot	*obj;
	t_list	*temp;

	obj = (t_spot*)malloc(sizeof(t_spot));
	obj->intensity = 0.2;
	ft_set_vector(&obj->position, 100, 100, 100);
	if (read_line(fd, obj))
		return (1);
	temp = ft_lstnew(obj, sizeof(t_spot));
	temp->content_size = SPOT;
	ft_lstadd(light, temp);
	return (0);
}