/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:44:06 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 20:05:16 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		ft_parse_dict_value(t_dict *dict, char **buf, int *size, char **value)
{
	ft_dict_search_value_start(buf, size);
	if (ft_parse_dict_value_help(buf, size, value) == 0)
		return (0);
	if (*value == 0)
	{
		dict->error = "Bad value";
		return (0);
	}
	return (1);
}

int		ft_parse_dict_key(t_dict *dict, char **buf, int *size, char **key)
{
	if (ft_parse_dict_number(buf, size, key) == 0)
		return (0);
	if (*key == 0)
	{
		dict->error = "Bad key";
		return (0);
	}
	return (1);
}

int		ft_parse_dict_record(t_dict *dict, char *buf, int length)
{
	int		size;
	int		spaces;
	char	*key;
	char	*value;

	size = length;
	ft_skip_spaces(&buf, &size);
	if (size <= 0)
		return (length);
	spaces = length - size;
	if (!ft_parse_dict_key(dict, &buf, &size, &key))
		return (spaces);
	if (!ft_parse_dict_value(dict, &buf, &size, &value))
	{
		free(key);
		return (spaces);
	}
	ft_sorted_dict_insert(dict, key, value);
	return (length - size);
}
