/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:44:06 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 20:02:16 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

char	*ft_parse_dict_strdup(char *str, int length)
{
	char	temp;
	char	*copy;

	temp = str[length];
	str[length] = 0;
	copy = ft_strdup(str);
	str[length] = temp;
	return (copy);
}

int		ft_parse_dict_number(char **buf, int *length, char **nbr)
{
	char	*pos;
	int		len;
	int		i;

	len = *length;
	pos = *buf;
	*nbr = NULL;
	i = 0;
	if (len == 0)
		return (0);
	ft_parse_dict_number_skip(buf, length);
	while (i < len && (pos[i] >= '0' && pos[i] <= '9'))
		i++;
	if (i == len)
		return (0);
	if (i > 0)
		*nbr = ft_parse_dict_strdup(pos, i);
	*buf = pos + i;
	*length = len - i;
	return (1);
}

int		ft_parse_dict_value_help(char **buf, int *length, char **value)
{
	char	*pos;
	int		len;
	int		i;
	int		j;

	len = *length;
	pos = *buf;
	*value = NULL;
	i = 0;
	if (*pos == '\n')
		return (-1);
	if (len == 0)
		return (0);
	while (i < len && pos[i] != '\n' && ft_dict_is_printable(pos[i]))
		i++;
	if (pos[i] != '\n')
		return (0);
	j = i;
	while (j >= 0 && ft_dict_is_space(pos[j]))
		j--;
	if (j >= 0)
		*value = ft_parse_dict_strdup(pos, j + 1);
	*buf = pos + i + 1;
	*length = len - i - 1;
	return (1);
}
