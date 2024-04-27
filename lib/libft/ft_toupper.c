/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:05:03 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:05:03 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

static int	ft_islower(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}
