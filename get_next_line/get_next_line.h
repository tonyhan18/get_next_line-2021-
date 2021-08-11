/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahan <hgdst14@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:47:07 by chahan            #+#    #+#             */
/*   Updated: 2021/08/09 20:47:08 by chahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char		*get_next_line(int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *str);

#endif