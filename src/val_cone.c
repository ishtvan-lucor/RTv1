/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:45:17 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/09 15:06:13 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	check_param(char *line, int *set)
{
	if (ft_strstr(line, CLR))
		set[0] = 1;
	else if (ft_strstr(line, SPC))
		set[1] = 1;
	else if (ft_strstr(line, RFL))
		set[2] = 1;
	else if (ft_strstr(line, ANGLE))
		set[3] = 1;
	else if (ft_strstr(line, POINT))
		set[4] = 1;
	else if (ft_strstr(line, AXIS))
		set[5] = 1;
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
		res += ft_putstr("ERROR: angle missed! MAN_CONF\n");
	if (!set_param[4])
		res += ft_putstr("ERROR: point missed! MAN_CONF\n");
	if (!set_param[5])
		res += ft_putstr("ERROR: axis missed! MAN_CONF\n");
	return (res);
}

static int	find_data(char *line, t_cone *cone)
{
	char	**s;
	int		error_f;
	size_t	len;

	if ((len = ft_wordssplit(line, ' ')) == 0)
		return (ft_putstr("Error: empty line!\n"));
	if (!(s = ft_strsplit(line, ' ')))
		return (ft_putstr("ERROR: to big string=)\n"));
	if (!ft_strcmp(s[0], POINT))
		error_f = val_vector(s, &cone->start, len);
	else if (!ft_strcmp(s[0], AXIS))
		error_f = val_vector(s, &cone->axis, len);
	else if (!ft_strcmp(s[0], ANGLE))
		error_f = val_double_cord(s, &cone->angle, len);
	else if (!ft_strcmp(s[0], CLR))
		error_f = val_color(s, &cone->clr, len);
	else if (!ft_strcmp(s[0], RFL))
		error_f = val_double_cord(s, &cone->rfl, len);
	else if (!ft_strcmp(s[0], SPC))
		error_f = val_int_cord(s, &cone->spcl, len);
	else
		error_f = ft_putstr("ERROR: invalid parameter of cone! MAN_CONF\n");
	ft_free_after_split(s, len);
	return (error_f);
}

static int	read_line(int fd, t_cone *s)
{
	char	*line;
	int		param_set[6];

	bzero(param_set, 24);
	while (get_next_line(fd, &line) == 1)
	{
		if (!ft_strcmp(line, DELIMITR))
			break ;
		if (find_data(line, s))
		{
			free(line);
			return (ft_putstr("ERROR: invalid cone! MAN_CONF\n"));
		}
		check_param(line, param_set);
		free(line);
	}
	free(line);
	if (check_presence_main_param(param_set))
		return (ft_putstr("Some parameters in cone missed=)\n"));
	return (0);
}

int			val_cone(int fd, t_list **prim)
{
	t_cone	*obj;
	t_list	*temp;

	if (!(obj = (t_cone*)malloc(sizeof(t_cone))))
		return (ft_putstr("Memory didn't allocated for cone!\n"));
	if (read_line(fd, obj))
	{
		free(obj);
		return (1);
	}
	temp = ft_lstnew(obj, sizeof(t_cone));
	temp->content_size = CONE;
	ft_lstadd(prim, temp);
	free(obj);
	return (0);
}
