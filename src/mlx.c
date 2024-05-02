/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/05/02 21:00:55 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
	{
		cub->ret = -12;
		return ;
	}
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	if (cub->win == NULL)
	{
		cub->ret = -12;
		return ;
	}
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (cub->img == NULL)
	{
		cub->ret = -12;
		return ;
	}
	cub->addr = mlx_get_data_addr(cub->img, &cub->bpp, &cub->llength,
			&cub->endian);
	if (cub->img == NULL)
		cub->ret = -12;
}

int	destruct_mlx(t_cub *cub)
{
	if (cub->win)
		mlx_clear_window(cub->mlx, cub->win);
	if (cub->img)
		mlx_destroy_image(cub->mlx, cub->img);
	cub->img = NULL;
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	cub->win = NULL;
	if (cub->mlx)
		ft_free_single((void **)&cub->mlx);
	cub->mlx = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}
