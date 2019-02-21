/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:49:50 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/21 19:14:45 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	check_param(char *line, int *set)
{
	if (ft_strstr(line, CLR))
		set[0] = 1;
	else if (ft_strstr(line, SPC))
		set[1] = 1;
	else if (ft_strstr(line, RFL))
		set[2] = 1;
	else if (ft_strstr(line, RDS))
		set[3] = 1;
	else if (ft_strstr(line, CNTR))
		set[4] = 1;
}

static int	check_presence_main_param(const int *set_param)
{
	int	res;

	res = 0;
	if (!set_param[0])
		res += ft_putstr("ERROR: color missed! MAN_CONF\n");
	if (!set_param[1])
		res += ft_putstr("ERROR: specular missed! MAN_CONF\n");
	if (!set_param[2])
		res += ft_putstr("ERROR: reflective missed! MAN_CONF\n");
	if (!set_param[3])
		res += ft_putstr("ERROR: radius missed! MAN_CONF\n");
	if (!set_param[4])
		res += ft_putstr("ERROR: center missed! MAN_CONF\n");
	return (res);
}

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
	int		param_set[5];

	bzero(param_set, 20);
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
			return (ft_putstr("ERROR: invalid sphere! MAN_CONF\n"));
		}
		free(line);
	}
	if (check_presence_main_param(param_set))
		return (ft_putstr("Some parameters in sphere missed=)\n"));
	return (0);
}

int			val_sphere(int fd, t_list **prim)
{
	t_sphere	*obj;
	t_list		*temp;

	if (!(obj = (t_sphere*)malloc(sizeof(t_sphere))))
		return (ft_putstr("Memory didn't allocated for sphere!\n"));
	if (read_line(fd, obj))
		return (1);
	temp = ft_lstnew(obj, sizeof(t_sphere));
	temp->content_size = SPHERE;
	ft_lstadd(prim, temp);
	return (0);
}
