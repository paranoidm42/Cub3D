/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/05/02 20:50:23 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_struct(t_cub *cub)
{
	cub->ret = 0;
	cub->tmp0_0 = 0;
	cub->tmp0_1 = 0;
	cub->fd_path = 0;
	cub->tmp1_0 = NULL;
	cub->tmp1_1 = NULL;
	cub->tmp1_2 = NULL;
	cub->tmp1_3 = NULL;
	cub->tmp2_0 = NULL;
	cub->tmp2_1 = NULL;
	cub->map = NULL;
	ft_bzero(cub->count_path, (sizeof(size_t) * 4));
	ft_bzero(cub->fd_path_texture, (sizeof(int) * 4));
	ft_bzero(cub->count_color, (sizeof(size_t) * 2));
	ft_bzero(cub->color, (sizeof(int) * 6));
	ft_bzero(cub->color_final, (sizeof(int) * 2));
	cub->texture_no = NULL;
	cub->texture_so = NULL;
	cub->texture_we = NULL;
	cub->texture_ea = NULL;
	init_struct_aux_00(cub);
	init_struct_aux_01(cub);
}

void	init_struct_aux_00(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->img = NULL;
	cub->addr = NULL;
	cub->pos_x = 0;
	cub->pos_y = 0;
	cub->dir_x = 0.00000000001;
	cub->dir_y = 0.00000000001;
	cub->old_dir_x = 0;
	cub->ver_walk = 0;
	cub->hor_walk = 0;
	cub->turn_dir = 0;
	cub->plane_x = 0;
	cub->plane_y = 0;
	cub->old_plane_x = 0;
	cub->camera_wall = 0;
	cub->camera_x = 0;
}

void	init_struct_aux_01(t_cub *cub)
{
	cub->step_x = 0;
	cub->step_y = 0;
	cub->side_x = 0;
	cub->side_y = 0;
	cub->raydir_x = 0;
	cub->raydir_y = 0;
	cub->delta_x = 0;
	cub->delta_y = 0;
	cub->rotation = 0;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->hit = FALSE;
	cub->side = 0;
	cub->line_height = 0;
	cub->draw_start = 0;
	cub->draw_end = 0;
	cub->tex_x = 0;
	cub->tex_y = 0;
	cub->step = 0;
	cub->tex_pos = 0;
	cub->wall_x = 0;
}

int	destroy_struct(t_cub *cub)
{
	if (cub->texture_no)
		ft_free_double_int(&cub->texture_no, (size_t)cub->tmp0_0);
	if (cub->texture_so)
		ft_free_double_int(&cub->texture_so, (size_t)cub->tmp0_0);
	if (cub->texture_we)
		ft_free_double_int(&cub->texture_we, (size_t)cub->tmp0_0);
	if (cub->texture_ea)
		ft_free_double_int(&cub->texture_ea, (size_t)cub->tmp0_0);
	if (cub->fd_path > 0)
		ft_close_fd(&cub->fd_path);
	destroy_struct_aux_00(cub);
	destruct_mlx(cub);
	init_struct(cub);
	return (0);
}

void	destroy_struct_aux_00(t_cub *cub)
{
	if (cub->tmp1_0)
		ft_free_single((void **)&cub->tmp1_0);
	if (cub->tmp1_1)
		ft_free_single((void **)&cub->tmp1_1);
	if (cub->tmp1_2)
		ft_free_single((void **)&cub->tmp1_2);
	if (cub->tmp1_3)
		ft_free_single((void **)&cub->tmp1_3);
	if (cub->tmp2_0)
		ft_free_double(&cub->tmp2_0);
	if (cub->tmp2_1)
		ft_free_double(&cub->tmp2_1);
	if (cub->map)
		ft_free_double(&cub->map);
	if (cub->fd_path_texture[0])
	{
		cub->tmp0_0 = 0;
		while (cub->tmp0_0 < 4)
			close(cub->fd_path_texture[cub->tmp0_0++]);
	}
}
