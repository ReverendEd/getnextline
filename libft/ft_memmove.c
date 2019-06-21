/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:00:37 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/29 11:16:25 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*temp;
	const unsigned char	*temp2;

	if (dst == NULL || src == NULL)
		return (dst);
	i = 0;
	temp = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	if (temp2 < temp)
		while (++i <= len)
			temp[len - i] = temp2[len - i];
	else
		while (len-- > 0)
			*(temp++) = *(temp2++);
	return (dst);
}
