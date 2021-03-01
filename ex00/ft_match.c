/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:04:39 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 18:35:35 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

t_match	*ft_create_match(
			char *key,
			int key_length)
{
	t_match		*match;

	match = malloc(sizeof(t_match));
	if (!match)
		return (NULL);
	match->value = NULL;
	match->replace_count = 0;
	match->key = key;
	match->key_length = key_length;
	return (match);
}
