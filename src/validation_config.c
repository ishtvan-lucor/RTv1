/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_config.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:58:34 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/12/13 21:16:44 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int	validation_config(char *config)
{
	if (ft_strcmp(config, "yes"))
		return (1);
	return (0);
}