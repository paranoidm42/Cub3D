/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:05:56 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_wall(t_cub *cub, size_t x)
{
	if (cub->side)
		cub->wall_x = cub->pos_x + (cub->camera_wall * cub->raydir_x);
	else
		cub->wall_x = cub->pos_y + (cub->camera_wall * cub->raydir_y);
	cub->wall_x -= floor(cub->wall_x);
	cub->tex_x = (int)(cub->wall_x * cub->tmp0_0);
	if ((cub->side == 0 && cub->raydir_x > 0) || (cub->side == 1 && \
	cub->raydir_y < 0))
		cub->tex_x = (cub->tmp0_0 - cub->tex_x - 1);
	cub->step = cub->tmp0_0 / (double)cub->line_height;
	cub->tex_pos = (cub->draw_start - HEIGHT / 2 + cub->line_height / 2) \
	* cub->step;
	cub_side_exist(cub, x);
}

void	cub_side_exist(t_cub *cub, size_t x)
{
	if (!cub->side)
	{
		if (cub->raydir_x < 0)
			draw_ver(x, cub, cub->texture_no);
		else
			draw_ver(x, cub, cub->texture_so);
	}
	else
	{
		if (cub->raydir_y < 0)
			draw_ver(x, cub, cub->texture_we);
		else
			draw_ver(x, cub, cub->texture_ea);
	}
}

void	draw_ver(int x, t_cub *cub, int **text)
{
	size_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < (size_t)cub->draw_start)
			ft_mlx_pixel_put(cub, (WIDTH - x - 1), y, cub->color_final[0]);
		else if (y >= (size_t)cub->draw_start && y <= (size_t)cub->draw_end)
		{
			cub->tex_y = (int)cub->tex_pos & (cub->tmp0_0 - 1);
			cub->tex_pos += cub->step;
			ft_mlx_pixel_put(cub, (WIDTH - x - 1), y, \
				text[cub->tex_y][cub->tex_x]);
		}
		else
			ft_mlx_pixel_put(cub, (WIDTH - x - 1), y, cub->color_final[1]);
		y++;
	}
}

void	ft_mlx_pixel_put(t_cub *cub, int x, int y, int pixel)
{
	char	*dest;

	if (y >= HEIGHT || x >= WIDTH || y < 0 || x < 0)
		return ;
	dest = cub->addr + (y * cub->llength) + (x * (cub->bpp / 8));
	*(unsigned int *)dest = pixel;
}
