/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:31:28 by delyn             #+#    #+#             */
/*   Updated: 2021/02/02 22:33:18 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			ft_memcpy(char *dst, char *src, unsigned int size)
{
	while (size != 0)
	{
		*dst++ = *src++;
		size--;
	}
}

int				ft_memcmp(char *s1, char *s2, unsigned int size)
{
	int i;

	i = 0;
	while (size != 0 && s1[i] == s2[i])
	{
		i++;
		size--;
	}
	if (size == 0)
		return (0);
	return (unsigned char)s1[i] - (unsigned char)s2[i];
}
