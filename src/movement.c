/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:00:06 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	movement(t_cub *cub)
{
	movement_vertical(cub);
	movement_horizontal(cub);
	movement_player(cub);
}

void	movement_vertical(t_cub *cub)
{
	if (cub->map[(int)(cub->pos_x + (cub->ver_walk * \
			(cub->dir_x * VALUE_MOV)))][(int)cub->pos_y] == '0')
		cub->pos_x += (cub->ver_walk * (cub->dir_x * VALUE_MOV));
	if (cub->map[(int)(cub->pos_x)][(int)(cub->pos_y + (cub->ver_walk * \
					(cub->dir_y * VALUE_MOV)))] == '0')
		cub->pos_y += (cub->ver_walk * (cub->dir_y * VALUE_MOV));
}

void	movement_horizontal(t_cub *cub)
{
	if (cub->map[(int)(cub->pos_x + (cub->hor_walk * \
			(cub->plane_x * VALUE_MOV)))][(int)cub->pos_y] == '0')
		cub->pos_x += (cub->hor_walk * (cub->plane_x * VALUE_MOV));
	if (cub->map[(int)cub->pos_x][(int)(cub->pos_y + (cub->hor_walk * \
					(cub->plane_y * VALUE_MOV)))] == '0')
		cub->pos_y += (cub->hor_walk * (cub->plane_y * VALUE_MOV));
}

void	movement_player(t_cub *cub)
{
	cub->rotation = (cub->turn_dir * VALUE_MOV);
	cub->old_dir_x = cub->dir_x;
	cub->dir_x = ((cub->dir_x * cos(cub->rotation)) - \
			(cub->dir_y * sin(cub->rotation)));
	cub->dir_y = ((cub->old_dir_x * sin(cub->rotation)) + \
			(cub->dir_y * cos(cub->rotation)));
	cub->old_plane_x = cub->plane_x;
	cub->plane_x = ((cub->plane_x * cos(cub->rotation)) - \
			(cub->plane_y * sin(cub->rotation)));
	cub->plane_y = ((cub->old_plane_x * sin(cub->rotation)) + \
			(cub->plane_y * cos(cub->rotation)));
	cub->rotation = 0;
}
