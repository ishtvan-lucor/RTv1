/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usable_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:05:07 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/07 17:50:32 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USABLE_STRUCTS_H
# define USABLE_STRUCTS_H
# define UC unsigned char
# define CMR "camera"
# define CNTR "center"
# define RDS "radius"
# define CLR "color"
# define RFL "reflective"
# define SPC "specular"
# define INTN "intensity"
# define PSTN "position"
# define DELIMITR "+"

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
