/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:36:14 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/29 11:15:23 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	temp = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	while (i < n)
	{
		temp[i] = temp2[i];
		if (temp[i] == (unsigned char)c)
		{
			return ((void*)(dst + i + 1));
		}
		i++;
	}
	return (NULL);
}
