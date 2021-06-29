/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:44:18 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/16 16:44:32 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_strchr(const char *s, int c)
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

char			*ft_strjoin(char const *s1, char const *s2)
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
	if (!(rt = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(rt, (char *)s1, ft_strlen((char *)s1) + 1);
	ft_strlcpy(rt + ft_strlen((char *)s1), (char *)s2,
				ft_strlen((char *)s2) + 1);
	return (rt);
}

char			*ft_substr(char const *p, unsigned int start, size_t len)
{
	char	*str;
	char	*s;

	s = (char *)p;
	if (!s)
		return (NULL);
	if (len >= (size_t)(ft_strlen(s) - (int)start))
	{
		len = ft_strlen(s) - (int)start;
		if (len < 0)
			len = 0;
	}
	if ((int)start >= ft_strlen(s))
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

void			*ft_calloc_set(size_t count, size_t size)
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

int				get_next_line(int fd, char **line)
{
	int			r;
	static char	*sav[10240];
	char		buff[BUFFER_SIZE + (r = 1)];
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	sav[fd] == NULL ? sav[fd] = ft_calloc_set(1, (0 + 1) * sizeof(char)) : NULL;


	while (!(ft_strchr(sav[fd], '\n')) && (r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = 0;
		temp = ft_strjoin(sav[fd], buff);
		ft_memdel((void **)&sav[fd]);
		sav[fd] = temp;
	}
	
	
	if (r == 0)
		*line = ft_strdup(sav[fd]);
	else if (r > 0)
		*line = ft_substr(sav[fd], 0, (ft_strchr(sav[fd], '\n') - sav[fd]));
	else
		return (-1);

	temp = ft_strdup(sav[fd] + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));

	ft_memdel((void **)&sav[fd]);
	sav[fd] = temp;
	
	return (r == 0 ? 0 * ft_memdel((void **)&sav[fd]) : 1);
}
