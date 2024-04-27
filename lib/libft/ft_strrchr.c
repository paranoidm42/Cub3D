/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:04:42 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:04:42 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	long long int	len;

	len = (long long int)ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (unsigned char)c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
