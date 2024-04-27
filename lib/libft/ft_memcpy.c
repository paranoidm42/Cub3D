/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:03:04 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:03:04 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*destcast;
	unsigned char		*srccast;
	size_t				i;

	if ((dest == NULL) && (src == NULL) && (len > 0))
		return (NULL);
	destcast = (unsigned char *)dest;
	srccast = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		destcast[i] = srccast[i];
		i++;
	}
	return (dest);
}
