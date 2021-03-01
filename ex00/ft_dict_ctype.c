/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_ctype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:00:43 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 20:02:58 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		ft_dict_is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int		ft_dict_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

void	ft_skip_spaces(char **buf, int *length)
{
	int		i;
	char	*pos;
	int		len;

	pos = *buf;
	len = *length;
	i = 0;
	while (i < len && ft_dict_is_space(pos[i]))
		i++;
	*length = len - i;
	*buf = pos + i;
}

void	ft_dict_search_value_start(char **buf, int *length)
{
	int		i;
	char	*str;
	int		size;

	size = *length;
	str = *buf;
	i = 0;
	while (i < size && str[i] != ':' && str[i] != '\n')
		i++;
	if (str[i] == ':')
	{
		i++;
		while (i < size && str[i] != '\n' && ft_dict_is_space(str[i]))
			i++;
	}
	*buf = str + i;
	*length = size - i;
}

void	ft_parse_dict_number_skip(char **buf, int *length)
{
	char	*pos;
	int		len;

	len = *length;
	pos = *buf;
	if (*pos == '+')
	{
		pos++;
		len--;
	}
	*buf = pos;
	*length = len;
}
