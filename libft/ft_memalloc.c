/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:27:35 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/22 17:36:14 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	char	*mem;

	i = 0;
	mem = malloc(size);
	if (!mem)
		return (NULL);
	while (size > 0)
	{
		mem[i] = 0;
		i++;
		size--;
	}
	return (mem);
}
