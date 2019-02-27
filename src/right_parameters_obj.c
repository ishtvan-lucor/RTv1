/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_parameters_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:56:11 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/02/27 21:11:23 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_zero_vector(t_vector *vector)
{
	if (vector->x == 0.0 && vector->y == 0.0 && vector->z == 0.0)
		return (ft_putstr("Zero vector can't be direction vector!\n"));
	return (0);
}

int			analyze_light(t_list *l)
{
	while (l)
	{
		if (((t_alght*)(l))->intensity < 0.0 || ((t_alght*)(l))->intensity > 1.0)
			return (ft_putstr("Incorrect intensity of light! MAN_CONF\n"));
		if (l->content_size == DLS)
		{
			if (check_zero_vector(&((t_dls*)(l))->direction))
				return (1);
			else
				((t_dls*)(l))->direction = v_nrm(&((t_dls*)(l))->direction);
		}
		l = l->next;
	}
	return (0);
}

int			check_axis_obj(t_list *p)
{
	if (p->content_size == PLANE)
	{
		if (check_zero_vector(&((t_plane*)p)->nrm))
			return (1);
		else
			((t_plane*)p)->nrm = v_nrm(&((t_plane*)p)->nrm);
	}
	else if (p->content_size == CYLINDER)
	{
		if (check_zero_vector(&((t_cylinder*)p)->axis))
			return (1);
		else
			((t_cylinder*)p)->axis = v_nrm(&((t_cylinder*)p)->axis);
	}
	else if (p->content_size == CONE)
	{
		if (check_zero_vector(&((t_cone*)p)->axis))
			return (1);
		else
			((t_cone*)p)->axis = v_nrm(&((t_cone*)p)->axis);
	}
	return (0);
}

int			analyze_prim(t_list *p)
{
	while (p)
	{
		printf("---->   %zu\n", p->content_size);
		if (p->content_size == SPHERE)
			printf("abstract == %d, sphere == %d\n", ((t_aprm*)p)->spcl, ((t_sphere*)p)->spcl);
		else if (p->content_size == PLANE)
			printf("plan speculat = : %d\n", ((t_plane*)p->content)->spcl);

		if (((t_aprm*)(p))->rfl < 0 || ((t_aprm*)(p))->rfl > 1)
			return (ft_putstr("Incorrect reflective of object! MAN_CONF\n"));
		if (((t_aprm*)(p))->spcl < 10 || ((t_aprm*)(p))->spcl > 1000)
			return (ft_putstr("Incorrect specular of object! MAN_CONF\n"));
		if (p->content_size == SPHERE && ((t_sphere*)(p))->rds <= 0)
			return (ft_putstr("Incorrect radius of object! MAN_CONF\n"));
		if (p->content_size == CYLINDER && ((t_cylinder*)(p))->rds <= 0)
			return (ft_putstr("Incorrect radius of object! MAN_CONF\n"));
		if (check_axis_obj(p))
			return (1);
		if (p->content_size == CONE)
		{
			if (((t_cone*)p)->angle < 1 || ((t_cone*)p)->angle > 179)
				return (ft_putstr("Incorrect angle of object! MAN_CONF\n"));
			else
			{
				((t_cone*)p)->angle = (((t_cone*)p)->angle * M_PI / 180.0);
				//((t_cone*)p)->angle = pow(((t_cone*)p)->angle, 2) + 1;
			}
		}
		p = p->next;
	}
	return (0);
}

int			right_parameters_obj(t_list *prim, t_list *light)
{
	t_list	*obj;

	obj = light;
	if (analyze_light(obj))
		return (1);
	obj = prim;
	if (analyze_prim(obj))
		return (1);
	return (0);
}