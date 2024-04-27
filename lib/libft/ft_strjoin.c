/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:04:09 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:04:09 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joins;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	joins = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!joins)
		return (NULL);
	ft_strlcpy(joins, s1, (size_s1 + 1));
	ft_strlcpy((joins + size_s1), s2, (size_s2 + 1));
	return (joins);
}
