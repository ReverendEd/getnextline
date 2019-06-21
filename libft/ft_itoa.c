/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 10:02:16 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/29 23:49:05 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int				get_size(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

static unsigned int		is_neg(int nbr)
{
	if (nbr < 0)
		return ((unsigned int)(nbr * -1));
	else
		return ((unsigned int)nbr);
}

char					*ft_itoa(int nbr)
{
	char			*result;
	unsigned int	num;
	unsigned int	i;
	unsigned int	j;

	num = is_neg(nbr);
	j = (unsigned int)get_size(num);
	i = 0;
	result = (char*)malloc(sizeof(char) * (j + 1 + (nbr < 0 ? 1 : 0)));
	if (!result)
		return (0);
	if (nbr < 0 && (result[i] = '-'))
		j++;
	i = j - 1;
	while (num >= 10)
	{
		result[i] = (char)(num % 10 + 48);
		num /= 10;
		i--;
	}
	result[i] = (char)(num % 10 + 48);
	result[j] = '\0';
	return (result);
}
