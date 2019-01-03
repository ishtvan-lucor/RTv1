/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usable_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:05:07 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/12/27 17:07:19 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USABLE_STRUCTS_H
# define USABLE_STRUCTS_H
# define UC unsigned char

typedef union	u_color
{
	int 		color;
	UC			clr[3];
}				t_color;

typedef struct	s_image_specification
{
	int 		bpp;
	int 		sl;
	int 		endl;
}				t_is;

#endif
