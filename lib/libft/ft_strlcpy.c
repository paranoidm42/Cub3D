/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:04:19 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:04:19 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	size_src;

	size_src = ft_strlen(src);
	if (len == 0)
		return (size_src);
	if ((size_src + 1) < len)
		ft_memcpy(dest, src, (size_src + 1));
	else
	{
		ft_memcpy(dest, src, (len - 1));
		dest[len - 1] = '\0';
	}
	return (size_src);
}
