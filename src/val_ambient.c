/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:48:47 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/22 16:56:15 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	check_param(char *line, int *set)
{
	if (ft_strstr(line, INTN))
		*set = 1;
}

static int	check_presence_main_param(const int *set_param)
{
	int	res;

	res = 0;
	if (!(*set_param))
		res += ft_putstr("ERROR: intensity missed! MAN_CONF\n");
	return (res);
}

static int	find_data(char *line, t_ambient *light)
{
	char	**s;
	int		error_f;
	size_t	len;

	len = ft_wordssplit(line, ' ');
	if (!(s = ft_strsplit(line, ' ')))
		return (ft_putstr("ERROR: to big string=)\n"));
	if (!ft_strcmp(s[0], INTN))
		error_f = val_double_cord(s, &light->intensity, len);
	else
		error_f = ft_putstr("ERROR: invalid parameter of light! MAN_CONF\n");
	ft_free_after_split(s, len);
	return (error_f);
}

static int	read_line(int fd, t_ambient *s)
{
	char	*line;
	int		param_set;

	param_set = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!ft_strcmp(line, DELIMITR))
		{
			free(line);
			break ;
		}
		check_param(line, &param_set);
		if (find_data(line, s))
		{
			free(line);
			return (ft_putstr("ERROR: invalid ambient light! MAN_CONF\n"));
		}
		free(line);
	}
	if (check_presence_main_param(&param_set))
		return (ft_putstr("Some parameters in ambient light missed=)\n"));
	return (0);
}

int			val_ambient(int fd, t_list **light)
{
	t_ambient	*obj;
	t_list		*temp;

	if (!(obj = (t_ambient*)malloc(sizeof(t_ambient))))
		return (ft_putstr("Memory didn't allocated for ambient light!\n"));
	if (read_line(fd, obj))
		return (1);
	temp = ft_lstnew(obj, sizeof(t_ambient));
	temp->content_size = AMBIENT;
	ft_lstadd(light, temp);
	return (0);
}
