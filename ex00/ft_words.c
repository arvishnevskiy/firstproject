/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 21:47:28 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 19:58:51 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		ft_words_push_front(t_word **begin_list, char *value, int size)
{
	t_word	*node;

	node = malloc(sizeof(t_word));
	if (!node)
		return (0);
	node->value = value;
	node->size = size;
	node->next = *begin_list;
	*begin_list = node;
	return (1);
}

void	ft_words_clear(t_word *word)
{
	t_word	*next;

	while (word != NULL)
	{
		next = word->next;
		free(word);
		word = next;
	}
}

int		ft_words_replace(t_word **begin_list, char *value, int count)
{
	t_word	*next;
	t_word	*node;
	int		i;

	if (count == 0)
		return (ft_words_push_front(begin_list, value, 1));
	node = *begin_list;
	i = 0;
	while (i < count)
	{
		i += node->size;
		next = node->next;
		free(node);
		node = next;
	}
	*begin_list = node;
	return (ft_words_push_front(begin_list, value, count + 1));
}
