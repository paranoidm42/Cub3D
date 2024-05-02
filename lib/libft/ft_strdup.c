/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:04:00 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:04:00 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptret;

	len = ft_strlen(str);
	ptret = malloc(len + 1);
	if (!ptret)
		return (NULL);
	if (ft_memcpy(ptret, str, len) == NULL)
		return (NULL);
	ptret[len] = '\0';
	return (ptret);
}
