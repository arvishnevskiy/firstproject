/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:31:28 by delyn             #+#    #+#             */
/*   Updated: 2021/02/06 20:55:37 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	char	*end;

	end = str;
	while (*end != 0)
		end++;
	return (end - str);
}

char			*ft_strcpy(char *dest, char *src)
{
	ft_memcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}

int				ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

char			*ft_strdup(char *src)
{
	unsigned int	size;
	char			*dst;

	size = ft_strlen(src) + 1;
	dst = (char*)malloc(sizeof(char) * size);
	if (dst != 0)
	{
		ft_memcpy(dst, src, size);
	}
	return (dst);
}

char			*ft_concat(char *s1, char *s2)
{
	int		size1;
	int		size2;
	char	*dst;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	dst = (char*)malloc(sizeof(char) * (size1 + size2 + 1));
	if (dst)
	{
		ft_memcpy(dst, s1, size1);
		ft_memcpy(dst + size1, s2, size2 + 1);
	}
	return (dst);
}
