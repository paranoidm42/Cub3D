/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:00:10 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycasting(t_cub *cub)
{
	size_t	x;

	x = 0;
	while (x < WIDTH)
	{
		init_raycasting_var(cub, x);
		step_and_side(cub);
		dda(cub);
		get_line_height(cub);
		draw_wall(cub, x);
		x++;
	}
}

void	init_raycasting_var(t_cub *cub, size_t x)
{
	cub->camera_x = 2 * x / (double)(WIDTH) - 1;
	cub->raydir_x = cub->dir_x + cub->plane_x * cub->camera_x;
	cub->raydir_y = cub->dir_y + cub->plane_y * cub->camera_x;
	if (cub->raydir_x == 0)
		cub->raydir_x = 1e30;
	else
		cub->delta_x = fabs(1 / cub->raydir_x);
	if (cub->raydir_y == 0)
		cub->raydir_y = 1e30;
	else
		cub->delta_y = fabs(1 / cub->raydir_y);
	cub->map_x = (int)cub->pos_x;
	cub->map_y = (int)cub->pos_y;
	cub->hit = FALSE;
}

void	step_and_side(t_cub *cub)
{
	if (cub->raydir_x < 0)
	{
		cub->step_x = -1;
		cub->side_x = (cub->pos_x - cub->map_x) * cub->delta_x;
	}
	else
	{
		cub->step_x = 1;
		cub->side_x = (cub->map_x + 1.0 - cub->pos_x) * cub->delta_x;
	}
	if (cub->raydir_y < 0)
	{
		cub->step_y = -1;
		cub->side_y = (cub->pos_y - cub->map_y) * cub->delta_y;
	}
	else
	{
		cub->step_y = 1;
		cub->side_y = (cub->map_y + 1.0 - cub->pos_y) * cub->delta_y;
	}
}

void	dda(t_cub *cub)
{
	while (!cub->hit)
	{
		if (cub->side_x < cub->side_y)
		{
			cub->side_x += cub->delta_x;
			cub->map_x += cub->step_x;
			cub->side = 0;
			cub->camera_wall = (cub->side_x - cub->delta_x);
		}
		else
		{
			cub->side_y += cub->delta_y;
			cub->map_y += cub->step_y;
			cub->side = 1;
			cub->camera_wall = (cub->side_y - cub->delta_y);
		}
		if (cub->map[(int)cub->map_x][(int)cub->map_y] != '0')
			cub->hit = TRUE;
	}
}

void	get_line_height(t_cub *cub)
{
	cub->line_height = (int)(HEIGHT / cub->camera_wall);
	cub->draw_start = (-1 * cub->line_height) / 2 + HEIGHT / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->line_height / 2 + HEIGHT / 2;
	if (cub->draw_end >= HEIGHT)
		cub->draw_end = HEIGHT - 1;
}
