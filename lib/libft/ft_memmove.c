/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:03:10 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:03:10 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*undest;
	unsigned char	*unsrc;

	undest = (unsigned char *)dest;
	unsrc = (unsigned char *)src;
	if (unsrc < undest)
	{
		while (len > 0)
		{
			ft_memcpy(undest + (len - 1), unsrc + (len - 1), 1);
			len--;
		}
	}
	else
		ft_memcpy(undest, unsrc, len);
	return (dest);
}
