/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:15:41 by achater           #+#    #+#             */
/*   Updated: 2023/11/16 16:45:15 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f(unsigned long x, int signe)
{
	if ((signe == 1) && (x >= 9223372036854775807))
		return (-1);
	if ((signe == -1) && (x > 9223372036854775807))
		return (0);
	return (x * signe);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	unsigned long	x;

	signe = 1;
	x = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		x = (x * 10) + str[i] - '0';
		i++;
	}
	return (f(x, signe));
}
