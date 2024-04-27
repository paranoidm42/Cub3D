/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 00:58:52 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	build_texture(t_cub *cub)
{
	size_t	i;

	i = 0;
	while ((i < 4) && (cub->ret == 0))
	{
		cub->tmp1_2 = get_next_line(cub->fd_path_texture[i]);
		cub->tmp1_0 = (char *)ft_calloc(sizeof(char), 9);
		while (cub->tmp1_2 && (cub->ret == 0))
		{
			tmp_verification(cub, i);
			ft_free_single((void **)&cub->tmp1_2);
			cub->tmp1_2 = get_next_line(cub->fd_path_texture[i]);
		}
		i++;
	}
}

void	get_pixel_texture(t_cub *cub, const size_t i)
{
	char	*tmp;
	size_t	j[2];

	j[0] = 0;
	j[1] = 0;
	tmp = NULL;
	ft_free_single((void **)&cub->tmp1_2);
	cub->tmp1_2 = get_next_line(cub->fd_path_texture[i]);
	cub->tmp0_0 = (int)ft_strlen(cub->tmp1_2);
	cub->tmp1_0 = (char *)ft_calloc(sizeof(char), cub->tmp0_0);
	getting_p_texture(cub, j, i, tmp);
	ft_free_single((void **)&cub->tmp1_0);
	cub->tmp2_1 = ft_split(cub->tmp1_1, '\n');
	ft_free_single((void **)&cub->tmp1_1);
	cub->tmp0_0 -= 4;
}

void	tmp_verification(t_cub *cub, size_t i)
{
	if (!ft_strncmp(cub->tmp1_2, \
		"/* columns rows colors chars-per-pixel */", 41))
	{
		get_pixel_color(cub, i);
		get_pixel_texture(cub, i);
		if (!cub->tmp2_0 || !cub->tmp2_1)
			cub->ret = -11;
		else
		{
			if (i == 0)
				cub->texture_no = convert_texture(cub);
			else if (i == 1)
				cub->texture_so = convert_texture(cub);
			else if (i == 2)
				cub->texture_we = convert_texture(cub);
			else
				cub->texture_ea = convert_texture(cub);
			
		}
		ft_free_double(&cub->tmp2_0);
		ft_free_double(&cub->tmp2_1);
	}
}

void	getting_p_texture(t_cub *cub, size_t j[], size_t i, char *tmp)
{
	while (cub->tmp1_2 && ft_strncmp(cub->tmp1_2, "};", 2))
	{
		j[0] = 0;
		j[1] = 0;
		while (cub->tmp1_2[j[0]])
		{
			while (cub->tmp1_2[j[0]] && (ft_strchr("\"", cub->tmp1_2[j[0]]) \
				|| (cub->tmp1_2[j[0]] == ',' && (int)j[0] == cub->tmp0_0 - 2)))
				j[0]++;
			cub->tmp1_0[j[1]++] = cub->tmp1_2[j[0]++];
		}
		if (cub->tmp1_1)
		{
			tmp = ft_strjoin(cub->tmp1_1, cub->tmp1_0);
			ft_free_single((void **)&cub->tmp1_1);
			cub->tmp1_1 = tmp;
			tmp = NULL;
		}
		else
			cub->tmp1_1 = ft_strdup(cub->tmp1_0);
		ft_bzero(cub->tmp1_0, (sizeof(char) * cub->tmp0_0));
		ft_free_single((void **)&cub->tmp1_2);
		cub->tmp1_2 = get_next_line(cub->fd_path_texture[i]);
	}
}
