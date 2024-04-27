/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 00:59:01 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	cub3d(t_cub *cub)
{
	mlx_hook(cub->win, 02, 1L << 0, &key_pressed, cub);
	mlx_hook(cub->win, 03, 1L << 1, &key_unpressed, cub);
	mlx_hook(cub->win, 17, 0, &quit, cub);
	mlx_loop_hook(cub->mlx, &play, cub);
	mlx_loop(cub->mlx);
}

int	play(t_cub *cub)
{
	movement(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (1);
}

int	key_pressed(int key, t_cub *cub)
{
	if (key == W_KEY)
		cub->ver_walk = 1;
	else if (key == S_KEY)
		cub->ver_walk = -1;
	else if (key == A_KEY)
		cub->hor_walk = 1;
	else if (key == D_KEY)
		cub->hor_walk = -1;
	else if (key == LEFT_KEY)
		cub->turn_dir = -1;
	else if (key == RIGHT_KEY)
		cub->turn_dir = 1;
	else if (key == ESC_KEY)
		quit(cub);
	return (0);
}

int	key_unpressed(int key, t_cub *cub)
{
	if (key == W_KEY)
		cub->ver_walk = 0;
	else if (key == S_KEY)
		cub->ver_walk = 0;
	else if (key == A_KEY)
		cub->hor_walk = 0;
	else if (key == D_KEY)
		cub->hor_walk = 0;
	else if (key == LEFT_KEY)
		cub->turn_dir = 0;
	else if (key == RIGHT_KEY)
		cub->turn_dir = 0;
	return (0);
}
