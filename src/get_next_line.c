/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur < ccur@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:32 by ccur              #+#    #+#             */
/*   Updated: 2024/04/28 00:59:51 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static char	*ft_read_file(int fd, char *backup);
static char	*ft_get_line(char *backup);
static char	*ft_save_line(char *backup);
static char	*ft_strjoin_gnl(char *s1, char const *s2);

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_read_file(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_save_line(backup);
	return (line);
}

static char	*ft_read_file(int fd, char *backup)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(backup, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		backup = ft_strjoin_gnl(backup, buff);
	}
	free(buff);
	return (backup);
}

static char	*ft_get_line(char *backup)
{
	int		i;
	char	*line;

	if (!backup[0])
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_save_line(char *backup)
{
	int		i;
	char	*save_line;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	save_line = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!save_line)
		return (NULL);
	i++;
	ft_strlcpy(save_line, &backup[i], (ft_strlen(&backup[i]) + 1));
	free(backup);
	return (save_line);
}

static char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*joins;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	joins = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!(joins))
		return (NULL);
	ft_strlcpy(joins, s1, (size_s1 + 1));
	ft_strlcpy((joins + size_s1), s2, (size_s2 + 1));
	free(s1);
	return (joins);
}
