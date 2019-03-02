/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_parameters_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:56:11 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/02 22:02:24 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_zero_vector(t_vector *vector)
{
	if (vector->x == 0.0 && vector->y == 0.0 && vector->z == 0.0)
		return (ft_putstr("Zero vector can't be direction vector!\n"));
	return (0);
}

static int	check_axis_obj(void *p, size_t type)
{
	if (type == PLANE)
	{
		if (check_zero_vector(&((t_plane*)p)->nrm))
			return (1);
		else
			((t_plane*)p)->nrm = v_nrm(&((t_plane*)p)->nrm);
	}
	else if (type == CYLINDER)
	{
		if (check_zero_vector(&((t_cylinder*)p)->axis))
			return (1);
		else
			((t_cylinder*)p)->axis = v_nrm(&((t_cylinder*)p)->axis);
	}
	else if (type == CONE)
	{
		if (check_zero_vector(&((t_cone*)p)->axis))
			return (1);
		else
			((t_cone*)p)->axis = v_nrm(&((t_cone*)p)->axis);
	}
	return (0);
}

static void	make_average_intensity(double coefficient, t_list *light)
{
	void	*p;

	while (light)
	{
		p = light->content;
		((t_alght*)p)->intensity = coefficient * ((t_alght*)p)->intensity;
		light = light->next;
	}
}

int			analyze_prim(t_list *list)
{
	void	*p;

	while (list)
	{
		p = list->content;
		if (((t_aprm*)(p))->rfl < 0 || ((t_aprm*)(p))->rfl > 1)
			return (ft_putstr("Incorrect reflective of object! MAN_CONF\n"));
		if (((t_aprm*)(p))->spcl < 10 || ((t_aprm*)(p))->spcl > 1000)
			return (ft_putstr("Incorrect specular of object! MAN_CONF\n"));
		if (list->content_size == SPHERE && ((t_sphere*)(p))->rds <= 0)
			return (ft_putstr("Incorrect radius of object! MAN_CONF\n"));
		if (list->content_size == CYLINDER && ((t_cylinder*)(p))->rds <= 0)
			return (ft_putstr("Incorrect radius of object! MAN_CONF\n"));
		if (check_axis_obj(p, list->content_size))
			return (1);
		if (list->content_size == CONE)
		{
			if (((t_cone*)p)->angle < 1 || ((t_cone*)p)->angle > 179)
				return (ft_putstr("Incorrect angle of object! MAN_CONF\n"));
			else
				((t_cone*)p)->angle = tan((((t_cone*)p)->angle * M_PI / 360.0));
		}
		list = list->next;
	}
	return (0);
}

int			analyze_light(t_list *light)
{
	double	intensity;
	t_list	*begin;
	void	*obj;

	begin = light;
	intensity = 0.0;
	while (light)
	{
		obj = light->content;
		if (((t_alght*)obj)->intensity < 0 || ((t_alght*)obj)->intensity > 1)
			return (ft_putstr("Incorrect intensity of light! MAN_CONF\n"));
		intensity += ((t_alght*)obj)->intensity;
		if (light->content_size == DLS)
		{
			if (check_zero_vector(&((t_dls*)obj)->direction))
				return (1);
			else
				((t_dls*)obj)->direction = v_nrm(&((t_dls*)obj)->direction);
		}
		light = light->next;
	}
	if (intensity > 1)
		make_average_intensity((1 / intensity), begin);
	return (0);
}
