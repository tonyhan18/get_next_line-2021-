/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:47:12 by chahan            #+#    #+#             */
/*   Updated: 2021/08/09 20:47:16 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (*(s++))
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (i < dstsize - dst_len - 1)
	{
		if (*((char *)src + i) == '\0')
			break ;
		*(dest + dst_len + i) = *((char *)src + i);
		i++;
	}
	*(dest + dst_len + i) = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cur_idx;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	cur_idx = 0;
	while (cur_idx < dstsize - 1)
	{
		if (*(src + cur_idx) == '\0')
			break ;
		*(dest + cur_idx) = *(src + cur_idx);
		cur_idx++;
	}
	*(dest + cur_idx) = '\0';
	return (src_len);
}

char	*ft_strdup(const char *str)
{
	char	*new_mem;
	int		str_len;

	str_len = ft_strlen(str);
	new_mem = (char *)malloc(str_len + 1);
	if (!new_mem)
		return (NULL);
	ft_strlcpy(new_mem, str, str_len + 1);
	return (new_mem);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 == 0)
		return (ft_strdup(s2));
	else
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_mem)
		return (NULL);
	ft_strlcpy(new_mem, s1, s1_len + 1);
	ft_strlcat(new_mem, s2, s1_len + s2_len + 1);
	return (new_mem);
}