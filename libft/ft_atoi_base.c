/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 22:03:44 by ikoloshy          #+#    #+#             */
/*   Updated: 2018/07/01 13:45:05 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_in_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= (base - 1) + '0');
	return ((c >= '0' && c <= '9') || (c >= 'a' && c < (base - 10 + 'a')) ||
			(c >= 'A' && c < (base - 10 + 'A')));
}

int	make_nbr(const char *str, int base, int flag)
{
	long	res;
	long	buff;

	res = 0;
	while (check_in_base(*str, base))
	{
		buff = res;
		if (*str - 'a' >= 0)
			res = res * base + (*str - 'a' + 10);
		else if (*str - 'A' >= 0)
			res = res * base + (*str - 'A' + 10);
		else
			res = res * base + (*str - '0');
		if (buff > res)
		{
			if (flag == -1)
				return (0);
			else
				return (-1);
		}
		str++;
	}
	return ((int)res * flag);
}

int	ft_atoi_base(const char *str, int base)
{
	int		flag;

	flag = 1;
	if (base < 2 || base > 36)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	return (make_nbr(str, base, flag));
}
