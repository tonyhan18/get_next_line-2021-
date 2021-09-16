/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:47:02 by chahan            #+#    #+#             */
/*   Updated: 2021/08/11 21:07:26 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	strlen2(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	return (i);
}

char	*trim(char **str)
{
	int		i;
	char	*ret;
	char	*tmp;
	int		len;

	if ((*str)[0] == '\0')
		return (NULL);
	len = strlen2(*str);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		ret[i] = (*str)[i];
		i++;
	}
	ret[i] = 0;
	tmp = ft_strdup(&(*str)[i + 1]);
	free(*str);
	*str = tmp;
	return (ret);
}

char	*initArray(char **saved_str, char **buf)
{
	if (!(*saved_str))
	{
		(*saved_str) = (char *)malloc(1);
		if (!(*saved_str))
			return (NULL);
		(*saved_str)[0] = 0;
	}
	(*buf) = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (NULL);
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char	*saved_str;
	char		*buf;
	char		*tmp;
	int			rdb;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!initArray(&saved_str, &buf))
		return (NULL);
	while (1)
	{
		rdb = read(fd, buf, BUFFER_SIZE);
		if (rdb <= 0)
			break ;
		buf[rdb] = 0;
		tmp = ft_strjoin(saved_str, buf);
		free(saved_str);
		saved_str = tmp;
	}
	free(buf);
	return (trim(&saved_str));
}
