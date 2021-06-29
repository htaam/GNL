/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:09:18 by tmatias           #+#    #+#             */
/*   Updated: 2021/03/15 15:59:44 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
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

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t		n;
	int			i;

	i = 0;
	n = siz;
	if (!src)
		return (0);
	if (n != 0)
	{
		while (--n != 0)
		{
			dst[i] = src[i];
			if ((dst[i++]) == 0)
				break ;
		}
	}
	if (n == 0)
	{
		if (siz != 0)
			dst[i] = 0;
		while (src[i++])
			;
	}
	return (&src[i] - src - 1);
}

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (!(*str == 0))
	{
		counter++;
		str++;
	}
	return (counter);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;

	size = ft_strlen((char *)s1) + 1;
	str = malloc(size);
	if (str)
		ft_memcpy(str, s1, size);
	return (str);
}

int	ft_memdel(void **ptr)
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
