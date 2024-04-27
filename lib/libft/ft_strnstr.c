/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:04:38 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:04:38 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *plac, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*find))
		return ((char *)plac);
	if (!(*plac) || (ft_strlen(find) > len))
		return (NULL);
	i = 0;
	while ((i < len) && plac[i])
	{
		j = 0;
		while (plac[i + j] == find[j] && plac[i + j] && find[j] && i + j < len)
			j++;
		if (find[j] == '\0')
			return ((char *)&plac[i]);
		i++;
	}
	return (NULL);
}
