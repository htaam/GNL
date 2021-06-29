/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:44:38 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/16 16:44:57 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

# ifndef FD_SIZE
#  define FD_SIZE 10240
# endif

void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t siz);
int				ft_strlen(char *str);
char			*ft_strdup(const char *s1);
int				ft_memdel(void **ptr);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *p, unsigned int start, size_t len);
void			*ft_calloc_set(size_t count, size_t size);
int				get_next_line(int fd, char **line);
#endif
