/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:01:20 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atod_aux(const char *str);

double	ft_atod(const char *str)
{
	int		i;
	int		sig;
	double	first;
	double	second;

	i = 0;
	sig = 1;
	first = 0;
	if (!ft_strchr(&str[i], '.'))
		return (ft_atoi(&str[i]));
	while (ft_isspace(str[i]) && (!(str[i] == '-') || !(str[i] == '+')))
		i++;
	if (str[i] == '-')
		sig = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		first = (first * 10) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	second = ft_atod_aux(&str[i]);
	return (sig * (first + second));
}

static double	ft_atod_aux(const char *str)
{
	int		i;
	int		len;
	double	second;

	i = 0;
	len = 0;
	second = 0;
	while (ft_isdigit(str[i]))
	{
		second = (second * 10) + (str[i] - '0');
		i++;
		len++;
	}
	while (len != 0)
	{
		second /= 10;
		len--;
	}
	return (second);
}
