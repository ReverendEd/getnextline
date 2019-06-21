/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:27:11 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/29 23:48:20 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		ft_putchar_fd(('-'), fd);
		number = -n;
	}
	else
	{
		number = n;
	}
	if (number >= 10)
	{
		ft_putnbr_fd((number / 10), fd);
	}
	ft_putchar_fd(((number % 10) + '0'), fd);
}
