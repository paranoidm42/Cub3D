/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:04:34 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:04:34 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;
	size_t			j;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while ((s1[i]) && (i < len))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	j = 0;
	while ((s2[j]) && (j < len))
		j++;
	if (i != j)
		return (s1[i] - s2[i]);
	return (0);
}
