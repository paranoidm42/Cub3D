/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 00:59:56 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	load_file(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->tmp2_0[i] && (cub->ret == 0))
	{
		cub->tmp1_0 = ft_strtrim(cub->tmp2_0[i], " ");
		if (ft_strncmp(cub->tmp2_0[i], "NO ", 3) == 0)
			load_texture(cub, i, 0);
		else if (ft_strncmp(cub->tmp2_0[i], "SO ", 3) == 0)
			load_texture(cub, i, 1);
		else if (ft_strncmp(cub->tmp2_0[i], "WE ", 3) == 0)
			load_texture(cub, i, 2);
		else if (ft_strncmp(cub->tmp2_0[i], "EA ", 3) == 0)
			load_texture(cub, i, 3);
		else if (ft_strncmp(cub->tmp2_0[i], "C ", 2) == 0)
			load_color(cub, i, 0);
		else if (ft_strncmp(cub->tmp2_0[i], "F ", 2) == 0)
			load_color(cub, i, 1);
		else if (ft_strlen(cub->tmp1_0))
			load_map(cub, &i);
		ft_free_single((void **)&cub->tmp1_0);
		if (cub->tmp2_0[i])
			i++;
	}
	ft_free_double(&cub->tmp2_0);
}

void	load_texture(t_cub *cub, const int i, const int index)
{
	if (cub->count_path[index] == 0)
	{
		cub->count_path[index] = 1;
		cub->tmp0_0++;
		cub->tmp2_1 = ft_split(cub->tmp2_0[i], ' ');
		if (cub->tmp2_1)
		{
			while (cub->tmp2_1[cub->tmp0_1])
				cub->tmp0_1++;
			if (cub->tmp0_1 != 2)
				cub->ret = -6;
			else
			{
				cub->fd_path_texture[index] = open(cub->tmp2_1[1], O_RDONLY);
				if (cub->fd_path_texture[index] == -1)
					cub->ret = -7;
			}
			cub->tmp0_1 = 0;
			ft_free_double(&cub->tmp2_1);
		}
		else
			cub->ret = -6;
	}
	else
		cub->ret = -6;
}

void	load_color(t_cub *cub, const int i, const int index)
{
	if (cub->count_color[index] == 0)
	{
		cub->count_color[index] = 1;
		cub->tmp0_0++;
		if (ft_strlen(cub->tmp2_0[i]) > 3)
		{
			cub->tmp2_1 = ft_split(&cub->tmp2_0[i][2], ',');
			if (cub->tmp2_1)
				load_color_aux_00(cub, index);
			else
				cub->ret = -8;
		}
		else
			cub->ret = -8;
	}
	else
		cub->ret = -8;
}

void	load_color_aux_00(t_cub *cub, const int index)
{
	size_t	j;
	size_t	k;

	j = 0;
	while (cub->tmp2_1[j])
		j++;
	if (j == 3)
	{
		k = (index * 3);
		j = 0;
		while (cub->tmp2_1[j] && (cub->ret == 0))
		{
			cub->color[k] = ft_atoi(cub->tmp2_1[j]);
			if (cub->color[k] < 0 || cub->color[k] >= 256)
				cub->ret = -8;
			j++;
			k++;
		}
		ft_free_double(&cub->tmp2_1);
	}
	else
		cub->ret = -8;
}

void	load_map(t_cub *cub, int *i)
{
	size_t	j;
	size_t	k;
	size_t	l;

	j = *i;
	k = 0;
	l = 0;
	while (cub->tmp2_0[*i])
	{
		l++;
		(*i)++;
	}
	cub->map = (char **)ft_calloc(sizeof(char *), (l + 1));
	while (cub->tmp2_0[j])
		cub->map[k++] = ft_strdup(cub->tmp2_0[j++]);
	j = 0;
	k = 0;
	l = 0;
}
