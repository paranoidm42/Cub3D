/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:04:53 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:04:53 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	size_t			i;
	size_t			size_str;

	size_str = ft_strlen(s);
	if (len > size_str)
		len = size_str;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	i = 0;
	if (start <= size_str)
	{
		while (i < len && s[start])
		{
			subs[i] = s[start + i];
			i++;
		}
	}
	subs[i] = '\0';
	return (subs);
}
