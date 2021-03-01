/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 21:32:52 by delyn             #+#    #+#             */
/*   Updated: 2021/02/11 14:15:09 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void		ft_dm_run_match(t_dict *dict, t_word **word,
				t_match *match, char *nbr)
{
	char	*value;

	match->key_length = match->replace_count + 1;
	value = ft_dict_get_value(dict, match->key);
	while (!value && match->replace_count > 0)
	{
		if (match->key[0] == '0')
		{
			match->replace_count = 0;
			value = ".";
			break ;
		}
		match->key[match->replace_count--] = '0';
		value = ft_dict_get_value(dict, match->key);
	}
	match->value = value;
	ft_dm_add_value(dict, word, match, nbr);
}

void		ft_dm_alloc_match(t_dict *dict, t_match **match,
				char **nbr_buf, int length)
{
	char	*buf;
	t_match	*new_match;

	buf = malloc(sizeof(char) * (length + 1));
	if (!buf)
	{
		dict->error = "Failed to allocate buffer";
		return ;
	}
	new_match = ft_create_match(buf, length);
	if (!new_match)
	{
		free(buf);
		dict->error = "Failes to allocate match struct";
		return ;
	}
	*nbr_buf = buf;
	*match = new_match;
}

void		ft_dm_full(t_dict *dict, t_word **word, char *nbr, int length)
{
	char	*nbr_buf;
	t_match	*match;
	int		octet_size;

	ft_dm_alloc_match(dict, &match, &nbr_buf, length);
	if (dict->error)
		return ;
	octet_size = 3;
	while (length > 0)
	{
		match->value = NULL;
		dict->error = NULL;
		ft_memcpy(nbr_buf, nbr, length);
		nbr_buf[length] = 0;
		match->replace_count = length - 1;
		ft_dm_run_match(dict, word, match, nbr);
		if (match->value)
			break ;
		length -= octet_size;
	}
	free(nbr_buf);
	free(match);
}

int			ft_dm_recalc_octet_size(t_nbr *nbr, int octet_size, unsigned int i)
{
	if (i > nbr->length)
	{
		octet_size = nbr->length % octet_size;
		if (octet_size == 0)
			octet_size = 3;
	}
	return (octet_size);
}

t_word		*ft_dict_match(t_dict *dict, t_nbr *nbr)
{
	unsigned int		i;
	unsigned int		octet_size;
	t_word				*word;
	char				*nbr_pos;

	word = NULL;
	i = 1;
	octet_size = 3;
	nbr_pos = nbr->value + nbr->length;
	while (i <= nbr->length)
	{
		nbr_pos -= 1;
		ft_dm_full(dict, &word, nbr_pos, i);
		i++;
	}
	return (word);
}
