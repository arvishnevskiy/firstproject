/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:54:22 by kelisabe          #+#    #+#             */
/*   Updated: 2021/02/07 19:57:13 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	ft_print_words(t_word *pos)
{
	char	*value;
	int		g;

	g = 0;
	while (pos)
	{
		value = pos->value;
		if (g > 0)
			write(1, " ", 1);
		ft_putstr(value);
		pos = pos->next;
		g++;
	}
	write(1, "\n", 1);
}
