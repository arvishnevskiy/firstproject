/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:26:47 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 19:59:54 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

t_dict			*ft_create_dict(void)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (dict)
	{
		dict->size = 0;
		dict->error = NULL;
		dict->head = NULL;
	}
	return (dict);
}

t_dict_node		*ft_create_dict_node(char *key, char *value)
{
	t_dict_node	*node;

	node = malloc(sizeof(t_dict_node));
	if (node)
	{
		node->key = key;
		node->value = value;
		node->key_length = ft_strlen(key);
		node->next = NULL;
	}
	return (node);
}

void			ft_dict_clear(t_dict *dict)
{
	t_dict_node	*node;
	t_dict_node	*head;

	head = dict->head;
	while ((node = head))
	{
		head = node->next;
		free(node->value);
		free(node->key);
		free(node);
	}
	free(dict);
}
