/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:00:30 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/21 17:45:12 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	check_param(char *line, int *set)
{
	if (ft_strstr(line, INTN))
		set[0] = 1;
	else if (ft_strstr(line, PSTN))
		set[1] = 1;
}

static int	check_presence_main_param(const int *set_param)
{
	int	res;

	res = 0;
	if (!set_param[0])
		res += ft_putstr("ERROR: intensity missed! MAN_CONF\n");
	if (!set_param[1])
		res += ft_putstr("ERROR: position missed! MAN_CONF\n");
	return (res);
}

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
		error_f = ft_putstr("ERROR: invalid parameter of spot! MAN_CONF\n");
	ft_free_after_split(s, len);
	return (error_f);
}

static int	read_line(int fd, t_spot *s)
{
	char	*line;
	int		param_set[2];

	bzero(param_set, 8);
	while (get_next_line(fd, &line) == 1)
	{
		if (!ft_strcmp(line, DELIMITR))
		{
			free(line);
			break ;
		}
		check_param(line, param_set);
		if (find_data(line, s))
		{
			free(line);
			return (ft_putstr("ERROR: invalid light spot! MAN_CONF"));
		}
		free(line);
	}
	if (check_presence_main_param(param_set))
		return (ft_putstr("Some parameters in light spot missed=)\n"));
	return (0);
}

int			val_spot(int fd, t_list **light)
{
	t_spot	*obj;
	t_list	*temp;

	if (!(obj = (t_spot*)malloc(sizeof(t_spot))))
		return (ft_putstr("Memory didn't allocated for light spot!"));
	if (read_line(fd, obj))
		return (1);
	temp = ft_lstnew(obj, sizeof(t_spot));
	temp->content_size = SPOT;
	ft_lstadd(light, temp);
	return (0);
}
