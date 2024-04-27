/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:02:53 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:02:53 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*ustr;
	size_t			i;

	ustr = (unsigned char *)str;
	i = 0;
	while (i < len)
	{
		if (ustr[i] == (unsigned char)c)
			return ((char *)&ustr[i]);
		i++;
	}
	return (NULL);
}
