/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:35:18 by delyn             #+#    #+#             */
/*   Updated: 2021/02/06 20:33:42 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void			ft_puts(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
}

void			ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void			ft_putnbr(int nb)
{
	char			str[20];
	unsigned int	size;
	unsigned int	pos;
	unsigned int	temp;

	size = 0;
	pos = 20;
	if (nb == 0)
		str[size++] = '0';
	if (nb < 0)
	{
		str[size++] = '-';
		temp = -nb;
	}
	else
		temp = nb;
	while (temp != 0)
	{
		str[--pos] = '0' + (temp % 10);
		temp /= 10;
	}
	while (pos != 20)
		str[size++] = str[pos++];
	write(1, str, size);
}
