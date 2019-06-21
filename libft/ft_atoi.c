/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 09:48:33 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/29 23:49:57 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	neg;
	int i;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] && (str[i] == ' '
		|| str[i] == '\n'
		|| str[i] == '\v'
		|| str[i] == '\t'
		|| str[i] == '\r'
		|| str[i] == '\f'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * neg);
}
