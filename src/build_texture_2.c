/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_texture_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/05/02 21:04:13 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_pixel_color(t_cub *cub, const size_t i)
{
	char	*tmp;
	size_t	j[2];

	tmp = NULL;
	ft_free_single((void **)&cub->tmp1_2);
	cub->tmp1_2 = get_next_line(cub->fd_path_texture[i]);
	ft_free_single((void **)&cub->tmp1_2);
	cub->tmp1_2 = get_next_line(cub->fd_path_texture[i]);
	while (cub->tmp1_2 && ft_strncmp(cub->tmp1_2, "/* pixels */", 12))
	{
		j[0] = 0;
		j[1] = 0;
		build_pixels(cub, i, j, tmp);
	}
	ft_free_single((void **)&cub->tmp1_0);
	cub->tmp2_0 = ft_split(cub->tmp1_1, '\n');
	ft_free_single((void **)&cub->tmp1_1);
}

int	**convert_texture(t_cub *cub)
{
	int		**tmp;
	size_t	i;

	tmp = NULL;
	tmp = (int **)ft_calloc(sizeof(int *), (size_t)cub->tmp0_0);
	i = 0;
	while ((int)i < cub->tmp0_0)
		tmp[i++] = (int *)ft_calloc(sizeof(int), (size_t)cub->tmp0_0);
	i = 0;
	tmp = converting_texture(cub, tmp, i);
	return (tmp);
}

void	build_pixels(t_cub *cub, size_t i, size_t j[], char *tmp)
{
	while (cub->tmp1_2[j[0]])
	{
		while (cub->tmp1_2[j[0]] && ft_strchr("\"c# ,", cub->tmp1_2[j[0]]) \
			&& j[0] != 1)
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
	ft_bzero(cub->tmp1_0, (sizeof(char) * 9));
	ft_free_single((void **)&cub->tmp1_2);
	cub->tmp1_2 = get_next_line(cub->fd_path_texture[i]);
}

int	**converting_texture(t_cub *cub, int **tmp, size_t i)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (cub->tmp2_1[i])
	{
		k = 0;
		while (cub->tmp2_1[i][k])
		{
			j = 0;
			while (cub->tmp2_0[j])
			{
				if (cub->tmp2_1[i][k] == cub->tmp2_0[j][0])
					tmp[i][k] = ft_atoi_base(&cub->tmp2_0[j][1], 16);
				j++;
			}
			k++;
		}
		i++;
	}
	return (tmp);
}
