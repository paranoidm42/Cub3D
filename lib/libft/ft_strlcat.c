/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:04:14 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:04:14 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t maxlen);

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	lim_dest;

	lim_dest = ft_strnlen(dest, len);
	if (lim_dest == len)
		return (lim_dest + ft_strlen(src));
	return (lim_dest + ft_strlcpy((dest + lim_dest), src, (len - lim_dest)));
}

static size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str > maxlen)
		return (maxlen);
	return (len_str);
}
