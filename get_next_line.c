/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:46:37 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/16 12:45:22 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*my_src;
	char	*my_dst;
	size_t	i;

	my_src = (char *)src;
	my_dst = (char *)dst;
	i = 0;
	if (!(my_src) && !(my_dst) && n > 0)
		return (dst);
	while (i < n)
	{
		my_dst[i] = my_src[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*d;

	a = 0;
	d = (char *)s;
	while (*(d + a))
	{
		if (*(d + a) == (char)c)
			return (d + a);
		a++;
	}
	if (c == 0)
		return (d + a);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*rt;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	rt = malloc(sizeof(char) * (len + 1));
	if (!(rt))
		return (NULL);
	ft_memcpy(rt, (char *)s1, ft_strlen((char *)s1));
	ft_memcpy(rt + ft_strlen((char *)s1), (char *)s2, ft_strlen((char *)s2));
	rt[len] = 0;
	return (rt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (len >= (size_t)(ft_strlen((char *)s) - (int)start))
	{
		len = ft_strlen((char *)s) - (int)start;
		if (len < 0)
			len = 0;
	}
	if ((int)start >= ft_strlen((char *)s))
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

void	*ft_calloc_set(size_t count, size_t size)
{
	void	*returning;
	int		len;
	void	*ptr;

	returning = malloc(count * size);
	if (returning == 0)
		return (NULL);
	len = size * count;
	ptr = returning;
	while (len--)
	{
		*(char *)returning = 0;
		returning = (char *)returning + 1;
	}
	return (ptr);
}
void	gnl_aux1(int r, char **sav, char **temp, char *buff)
{
	char	*buff2;

	buff2 = buff;
	buff2[r] = 0;
	*temp = ft_strjoin(*sav, buff2);
	ft_memdel((void **)sav);
	*sav = *temp;
}

int	gnl_aux2(int *r, char **sav, char **temp, char ***line)
{
	if (*r == 0)
		**line = ft_strdup(*sav);
	else if (r > 0)
		**line = ft_substr(*sav, 0, (ft_strchr(*sav, '\n') - *sav));
	if (r > 0)
		*temp = ft_strdup(*sav + (ft_strlen(**line) + 1));
	else
		*temp = ft_strdup(*sav + (ft_strlen(**line)));
	ft_memdel((void **)sav);
	*sav = *temp;
	return (*r);
}

int	get_next_line(int fd, char **line)
{
	int			r;
	static char	*sav[10240];
	char		buff[BUFFER_SIZE + (1)];
	char		*temp;

	r = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (sav[fd] == NULL)
		sav[fd] = ft_calloc_set(1, sizeof(char));
	while (!(ft_strchr(sav[fd], '\n')))
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r > 0)
			gnl_aux1(r, &sav[fd], &temp, buff);
		else
			break ;
	}
	if (r < 0)
		return (-1);
	if (gnl_aux2(&r, &sav[fd], &temp, &line) == 0)
		return (0 * ft_memdel((void **)&sav[fd]));
	return (1);
}
