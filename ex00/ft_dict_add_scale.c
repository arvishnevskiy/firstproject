/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_add_scale.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:45:32 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 16:30:12 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

char		*ft_dm_get_scale(t_dict *dict, char *nbr, int length)
{
	int i;

	if ((length < 3) || (length != 3) || (length % 3 != 1))
		return (NULL);
	i = 0;
	nbr[i++] = '1';
	while (i < length)
		nbr[i++] = '0';
	return (ft_dict_get_value(dict, nbr));
}

int			ft_dm_get_scale_replace_count(char *value, char *nbr, int length)
{
	int i;

	i = 1;
	while (i < length && nbr[i] == value[i])
		i++;
	return (i - 1);
}

int			ft_dm_is_scale(t_dict *dict, char *nbr, int length)
{
	int i;

	(void)dict;
	i = 0;
	if ((length < 3) || ((length != 3) && (length % 3 != 1)))
		return (0);
	if (nbr[i++] != '1')
		return (0);
	while (i < length)
	{
		if (nbr[i++] != '0')
			return (0);
	}
	return (1);
}

void		ft_dm_add_scale(t_dict *dict, t_word **word, char *nbr, int level)
{
	char	*scale;
	char	*buf;
	int		i;

	buf = malloc(sizeof(char) * (level + 1));
	i = 0;
	buf[i++] = '1';
	while (i < level)
		buf[i++] = '0';
	buf[i] = 0;
	scale = ft_dict_get_value(dict, buf);
	if (scale)
	{
		i = ft_dm_get_scale_replace_count(buf, nbr, level);
		ft_words_replace(word, scale, i);
	}
	else
	{
		dict->error = "Scale is not found";
	}
	free(buf);
}
