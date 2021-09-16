/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:54:28 by chahan            #+#    #+#             */
/*   Updated: 2021/09/16 16:03:55 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_next_str(int fd, char *next_str)
{
	char	*buffer;
	int		rd_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(next_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		next_str = ft_strjoin(next_str, buffer);
	}
	free(buffer);
	return (next_str);
}

char	*ft_get_next_line(char *next_str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!next_str[i])
		return (NULL);
	while (next_str[i] != '\n' && next_str[i])
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (next_str[i] != '\n' && next_str[i])
	{
		new_str[i] = next_str[i];
		i++;
	}
	if (next_str[i] == '\n')
	{
		new_str[i] = next_str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_split_next_str(char *next_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (next_str[i] && next_str[i] != '\n')
		i++;
	if (!next_str[i])
	{
		free(next_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(next_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (next_str[i])
		str[j++] = next_str[i++];
	str[j] = '\0';
	free(next_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_str[fd] = ft_read_to_next_str(fd, next_str[fd]);
	if (!next_str[fd])
		return (NULL);
	line = ft_get_next_line(next_str[fd]);
	next_str[fd] = ft_split_next_str(next_str[fd]);
	return (line);
}
