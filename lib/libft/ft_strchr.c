/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:03:51 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:03:51 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str != (unsigned char)c)
	{
		if (!(*str))
			return (0);
		str++;
	}
	return ((char *)str);
}
