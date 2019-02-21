/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_dls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:03:43 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/21 19:10:59 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	check_param(char *line, int *set)
{
	if (ft_strstr(line, INTN))
		set[0] = 1;
	else if (ft_strstr(line, AXIS))
		set[1] = 1;
}

static int	check_present_main_param(const int *set_param)
{
	int	res;

	res = 0;
	if (!set_param[0])
		res += ft_putstr("ERROR: intensity missed! MAN_CONF\n");
	if (!set_param[1])
		res += ft_putstr("ERROR: axis missed! MAN_CONF\n");
	return (res);
}

static int	find_data(char *line, t_dls *spot)
{
	char	**s;
	int		error_f;
	size_t	len;

	len = ft_wordssplit(line, ' ');
	if (!(s = ft_strsplit(line, ' ')))
		return (ft_putstr("ERROR: to big string=)\n"));
	if (!ft_strcmp(s[0], INTN))
		error_f = val_double_cord(s, &spot->intensity, len);
	else if (!ft_strcmp(s[0], AXIS))
		error_f = val_vector(s, &spot->direction, len);
	else
		error_f = ft_putstr("ERROR: invalid parameter of DLS! MAN_CONF\n");
	ft_free_after_split(s, len);
	return (error_f);
}

static int	read_line(int fd, t_dls *s)
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
			return (ft_putstr("ERROR: invalid DLS! MAN_CONF\n"));
		}
		free(line);
	}
	if (check_present_main_param(param_set))
		return (ft_putstr("Some parameters in DLS missed=)\n"));
	return (0);
}

int			val_dls(int fd, t_list **light)
{
	t_dls	*obj;
	t_list	*temp;

	if (!(obj = (t_dls*)malloc(sizeof(t_dls))))
		return (ft_putstr("Memory didn't allocated for DLS!\n"));
	if (read_line(fd, obj))
		return (1);
	temp = ft_lstnew(obj, sizeof(t_dls));
	temp->content_size = DLS;
	ft_lstadd(light, temp);
	return (0);
}
