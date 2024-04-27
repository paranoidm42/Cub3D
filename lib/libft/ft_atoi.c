/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 00:57:36 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	signal;
	int	nbr;

	signal = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = (10 * nbr) + (*str - '0');
		str++;
	}
	return (nbr * signal);
}
