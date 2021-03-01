/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_add_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:44:56 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 16:30:02 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void		ft_dm_add_value_base(t_dict *dict, t_word **word,
					t_match *match, char *nbr_buf)
{
	(*word)->size -= 1;
	match->value = ft_dict_get_value(dict, nbr_buf);
	if (!match->value)
		dict->error = "Digit is not found in dict";
	else
		ft_words_push_front(word, match->value, 1);
}

void		ft_dm_add_value(t_dict *dict, t_word **word,
					t_match *match, char *nbr)
{
	char	nbr_buf[2];
	int		is_base;

	is_base = 0;
	nbr_buf[0] = match->key[0];
	nbr_buf[1] = 0;
	if (match->value)
	{
		ft_words_replace(word, match->value, match->replace_count);
		is_base = ft_dm_is_scale(dict, match->key, match->key_length);
	}
	else if (match->replace_count == 0)
	{
		ft_dm_add_scale(dict, word, nbr, match->key_length);
		if (dict->error)
			return ;
		is_base = 1;
	}
	else
	{
		dict->error = "Number is not found in dict";
		return ;
	}
	if (is_base)
		ft_dm_add_value_base(dict, word, match, nbr_buf);
}
