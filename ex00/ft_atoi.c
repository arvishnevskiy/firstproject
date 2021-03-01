/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:10:41 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 18:50:34 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

char	*ft_ignore_spaces(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

t_nbr	*ft_parse_number(char *str)
{
	t_nbr	*nbr;

	nbr = malloc(sizeof(t_nbr));
	if (nbr == NULL)
		return (NULL);
	while (*str == '0')
		str++;
	if (*str == 0)
		str--;
	nbr->length = 0;
	nbr->value = str;
	while (*str >= '0' && *str <= '9')
	{
		nbr->length++;
		str++;
	}
	if (*str != 0)
	{
		free(nbr);
		return (NULL);
	}
	return (nbr);
}
