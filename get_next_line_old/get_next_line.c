/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:50:18 by chahan            #+#    #+#             */
/*   Updated: 2021/07/23 20:19:38 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_find_newline(char *in_buffer)
{
	int		i;

	i = 0;
	while (in_buffer[i])
	{
		if(in_buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			ft_split_lines(char **in_buffer, char **line, int idx)
{
	char	*tmp;
	int		len;

	(*in_buffer)[idx] = '\0';
	*line = ft_strdup(*in_buffer);
	len = ft_strlen(*in_buffer + idx + 1);
	if (len == 0)
	{
		free(*in_buffer);
		*in_buffer = 0;
		return (1);
	}
	tmp = ft_strdup(*in_buffer + idx + 1);
	free(*in_buffer);
	*in_buffer = tmp;
	return (1);
}

int			ft_return_all(char **in_buffer, char **line, int size)
{
	int		idx;

	if (size < 0)
		return (-1);
	if (*in_buffer && (idx = ft_find_newline(*in_buffer) >= 0))
		return (ft_split_lines(in_buffer, line, idx));
	else if (*in_buffer)
	{
		*line = *in_buffer;
		*in_buffer = 0;
		return (0);
	}
	else
	{
		*line = ft_strdup("");
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char		*in_buffer[FILE_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				size;
	int				idx;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		in_buffer[fd] = ft_strjoin(in_buffer[fd], buf);
		if ((idx = ft_find_newline(in_buffer[fd])) >= 0)
			return (ft_split_lines(&in_buffer[fd], line, idx));
	}
	return (ft_return_all(&in_buffer[fd], line, size));
}
