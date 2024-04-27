/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:02:00 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:02:00 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t qtd, size_t len)
{
	void	*ptr;

	if ((qtd >= INT_MAX) || (len >= INT_MAX))
		return (NULL);
	if (qtd == 0)
		qtd = 1;
	if (len == 0)
		len = 1;
	ptr = malloc(qtd * len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (qtd * len));
	return (ptr);
}
