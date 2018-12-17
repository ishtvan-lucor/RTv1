/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:51:27 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/12/17 18:22:07 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "objects.h"

# define WIN_W 900
# define WIN_H 900
/*
 * * FOV - (field of view) angle of view from camera
 * to make it 60 degree: Vw = Vh = d = 1
 */
# define FOV 1

typedef struct	s_basic
{
	void		*mlx;
	void		*win;
	void		*p_to_img;
	int 		*img;
	t_is		spec;
}				t_basic;

void			loop_and_catch_exits(t_basic *storage);
int				init_mlx(t_basic *s);
int				validation_config(char *config);
t_vector		point_from_screen_to_viewport(int x, int y);

#endif
