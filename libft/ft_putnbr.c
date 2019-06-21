/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 23:00:35 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/29 16:39:46 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	number;

	if (n < 0)
	{
		ft_putchar('-');
		number = -n;
	}
	else
	{
		number = n;
	}
	if (number >= 10)
	{
		ft_putnbr(number / 10);
	}
	ft_putchar((number % 10) + '0');
}
