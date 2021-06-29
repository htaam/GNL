/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:45:15 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/16 16:45:28 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			*ft_memset(void *b, int c, size_t len)
{
	void	*ptr;

	ptr = b;
	while (len--)
	{
		*(char *)b = (char)c;
		b = (char *)b + 1;
	}
	return (ptr);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t siz)
{
	char		*d;
	char		*s;
	size_t		n;

	n = siz;
	s = (char *)src;
	d = dst;
	if (!src)
		return (0);
	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*d++ = *s++) == 0)
				break ;
		}
	}
	if (n == 0)
	{
		if (siz != 0)
			*d = 0;
		while (*s++)
			;
	}
	return (s - (char *)src - 1);
}

int				ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (!(*str == 0))
	{
		counter++;
		str++;
	}
	return (counter);
}

char			*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;

	size = ft_strlen((char *)s1) + 1;
	str = malloc(size);
	if (str)
		ft_strlcpy(str, (char *)s1, size + 1);
	return (str);
}

int				ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = 0;
		return (1);
	}
	return (0);
}
