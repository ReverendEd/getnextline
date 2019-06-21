/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:44:31 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/29 11:16:27 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (dst == NULL || src == NULL)
		return (dst);
	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	while (n > 0)
	{
		*(ptr++) = *(ptr2++);
		n--;
	}
	return (dst);
}
