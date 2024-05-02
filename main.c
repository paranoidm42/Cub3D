/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:40:27 by ccur              #+#    #+#             */
/*   Updated: 2024/05/02 20:29:03 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	init_struct(&cub);
	if (argc == 2)
	{
		valid_and_build_structs(argv[1], &cub);
		if (cub.ret == 0)
		{
			get_player_position(&cub);
			init_mlx(&cub);
			cub3d(&cub);
		}
	}
	else
		cub.ret = -2;
	error(&cub);
	destroy_struct(&cub);
	return (0);
}

void	valid_and_build_structs(char *path, t_cub *cub)
{
	valid_path(path, cub);
	if (cub->ret == 0)
	{
		read_file(cub);
		if (cub->ret == 0)
		{
			load_file(cub);
			if (cub->ret == 0)
			{
				valid_map(cub);
				if (cub->ret == 0)
				{
					build_texture(cub);
					build_color(cub);
				}
			}
		}
	}
}

void	build_color(t_cub *cub)
{
	cub->color_final[0] = 0x00 << 24 | cub->color[0] << 16 | \
		cub->color[1] << 8 | cub->color[2];
	cub->color_final[1] = 0x00 << 24 | cub->color[3] << 16 | \
		cub->color[4] << 8 | cub->color[5];
	ft_bzero(cub->color, (sizeof(int) * 6));
}

void	get_player_position(t_cub *cub)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (cub->map[x] && (cub->pos_x == 0))
	{
		y = 0;
		while (cub->map[x][y] && (cub->pos_y == 0))
		{
			if (ft_strchr("NSEW", cub->map[x][y]))
			{
				cub->pos_x = (double)x + 0.5;
				cub->pos_y = (double)y + 0.5;
				set_player_position(cub, cub->map[x][y]);
				cub->map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
}

void	set_player_position(t_cub *cub, const char c)
{
	if (c == 'N')
	{
		cub->dir_x = -1.00;
		cub->plane_y = 0.66;
	}
	else if (c == 'S')
	{
		cub->dir_x = 1.00;
		cub->plane_y = -0.66;
	}
	else if (c == 'W')
	{
		cub->dir_y = -1.00;
		cub->plane_x = -0.66;
	}
	else
	{
		cub->dir_y = 1.00;
		cub->plane_x = 0.66;
	}
}
