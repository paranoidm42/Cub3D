/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 00:59:46 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_atoi_base(const char *str, int str_base)
{
	int	nbr;
	int	i;
	int	len;

	nbr = 0;
	i = 0;
	len = ((int)ft_strlen(str) - 1);
	while (str[i])
	{
		if (ft_strchr_int("0123456789ABCDEF", ft_toupper(str[i])) || \
			str[i] == '0')
		{
			nbr += (ft_strchr_int("0123456789ABCDEF", ft_toupper(str[i])) \
			* pow(str_base, len));
			len--;
		}
		else
			return (0);
		i++;
	}
	return (nbr);
}

int	ft_strchr_int(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (i);
		i++;
	}
	return (0);
}
