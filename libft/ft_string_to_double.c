/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 20:44:15 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/01/03 16:48:55 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_fractional_part(const char *str)
{
	double	fp;

	fp = 0;
	while (*str != '\0')
		str++;
	str--;
	while (*str >= '0' && *str <= '9')
	{
		fp = fp * 0.1 + (*str - '0');
		str--;
	}
	return (fp * 0.1);
}

double			ft_string_to_double(const char *str)
{
	double	res;
	int		flag;

	flag = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		res += get_fractional_part(str);
	return (res * flag);
}
