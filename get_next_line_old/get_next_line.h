/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:52:30 by chahan            #+#    #+#             */
/*   Updated: 2021/07/23 20:20:30 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef FILE_MAX
#  define FILE_MAX 42
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
