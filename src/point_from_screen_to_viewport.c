/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_from_screen_to_viewport.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:25:31 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/10 18:25:16 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RTv1.h"

t_vector	point_from_screen_to_viewport(int x, int y)
{
	t_vector	temp;

	temp.x = FOV * (x / WIN_W - 0.5);
	temp.y = FOV * (0.5 - y / WIN_H);
	temp.z = FOV;
	return (temp);
}

//TODO have idea that i'm to complicated this