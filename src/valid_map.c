/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 01:00:24 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	valid_map(t_cub *cub)
{
	valid_map_is_last(cub);
	if (cub->ret < 0)
		return ;
	valid_map_characteres(cub);
	if (cub->ret < 0)
		return ;
	map_tmp(cub);
	valid_map_is_valid(cub);
	ft_free_double(&cub->tmp2_0);
}

void	valid_map_is_last(t_cub *cub)
{
	if (cub->tmp0_0 == 6)
		cub->tmp0_0 = 0;
	else
		cub->ret = -9;
}

void	valid_map_characteres(t_cub *cub)
{
	size_t	count;
	size_t	len;
	size_t	i;

	count = 0;
	while (cub->map[cub->tmp0_0] && (cub->ret == 0))
	{
		cub->tmp1_0 = ft_strtrim(cub->map[cub->tmp0_0], " ");
		len = ft_strlen(cub->tmp1_0);
		ft_free_single((void *)&cub->tmp1_0);
		i = 0;
		while (cub->map[cub->tmp0_0][i] && (cub->ret == 0))
		{
			if (ft_strchr("NSEW", cub->map[cub->tmp0_0][i]))
				count++;
			if (((!ft_strchr("01NSEW", cub->map[cub->tmp0_0][i])) && \
	(!ft_isspace(cub->map[cub->tmp0_0][i]))) || (count > 1) || (len == 0))
				cub->ret = -9;
			i++;
		}
		cub->tmp0_0++;
	}
	cub->tmp0_0 = 0;
	if (count == 0)
		cub->ret = -9;
}

void	map_tmp(t_cub *cub)
{
	size_t	lin;
	size_t	max;

	lin = 0;
	max = 0;
	while (cub->map[lin])
	{
		cub->tmp0_0 = (int)ft_strlen(cub->map[lin]);
		if (cub->tmp0_0 > (int)max)
			max = cub->tmp0_0;
		lin++;
	}
	cub->tmp2_0 = (char **)ft_calloc(sizeof(char *), (lin + 1));
	while (cub->map[cub->tmp0_1])
	{
		cub->tmp2_0[cub->tmp0_1] = (char *)ft_calloc(sizeof(char), (max + 1));
		ft_memset(cub->tmp2_0[cub->tmp0_1], ' ', max);
		ft_memcpy(cub->tmp2_0[cub->tmp0_1], cub->map[cub->tmp0_1], \
				ft_strlen(cub->map[cub->tmp0_1]));
		cub->tmp0_1++;
	}
	cub->tmp0_0 = 0;
	cub->tmp0_1 = 0;
}

void	valid_map_is_valid(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub->tmp2_0[i] && (cub->ret == 0))
	{
		j = 0;
		while (cub->tmp2_0[i][j] && (cub->ret == 0))
		{
			if (cub->tmp2_0[i][j] == '0' || \
					ft_strchr("NSWE", cub->tmp2_0[i][j]))
			{
				if (i == 0 || !cub->tmp2_0[i + 1] || \
						j == 0 || !cub->tmp2_0[i][j + 1])
					cub->ret = -10;
				else if (ft_isspace(cub->tmp2_0[i - 1][j]) \
	|| ft_isspace(cub->tmp2_0[i + 1][j]) || ft_isspace(cub->tmp2_0[i][j + 1]) \
	|| ft_isspace(cub->tmp2_0[i][j - 1]))
					cub->ret = -10;
			}
			j++;
		}
		i++;
	}
}
