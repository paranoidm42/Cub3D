/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 00:59:35 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	error(const t_cub *cub)
{
	int	fd;

	fd = 2;
	if (cub->ret < 0)
	{
		ft_putendl_fd("Error", fd);
		if ((cub->ret >= -6) && (cub->ret <= -1))
			error_00(cub, fd);
		else if ((cub->ret >= -12) && (cub->ret <= -7))
			error_01(cub, fd);
	}
}

void	error_00(const t_cub *cub, const int fd)
{
	if (cub->ret == -1)
		ft_putendl_fd("Fatal: impossible to continue", fd);
	else if (cub->ret == -2)
		ft_putendl_fd("Invalid number of arguments", fd);
	else if (cub->ret == -3)
		ft_putendl_fd("Validation failed: Incorrect path length", fd);
	else if (cub->ret == -4)
		ft_putendl_fd("Validation failed: Incorrect path extension", fd);
	else if (cub->ret == -5)
		ft_putendl_fd("Validation failed: Impossible to open file path", fd);
	else if (cub->ret == -6)
		ft_putendl_fd("Load texture failed", fd);
}

void	error_01(const t_cub *cub, const int fd)
{
	if (cub->ret == -7)
		ft_putendl_fd("Validation failed: Impossible to open file texture", fd);
	else if (cub->ret == -8)
		ft_putendl_fd("Load color failed", fd);
	else if (cub->ret == -9)
		ft_putendl_fd("Validation failed: Incorrect map", fd);
	else if (cub->ret == -10)
		ft_putendl_fd("Validation failed: Invalid map", fd);
	else if (cub->ret == -11)
		ft_putendl_fd("Impossible to build the texture", fd);
	else if (cub->ret == -12)
		ft_putendl_fd("MLX return error", fd);
}
