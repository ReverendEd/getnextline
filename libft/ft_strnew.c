/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:26:35 by tsehr             #+#    #+#             */
/*   Updated: 2019/05/29 13:12:10 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;
	int		i;

	string = (char *)malloc(size + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (size > 0)
	{
		string[i] = 0;
		size--;
		i++;
	}
	string[i] = 0;
	return (string);
}
