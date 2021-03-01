/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:26:47 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 15:33:07 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int				ft_dict_cmp(t_dict_node *node1, t_dict_node *node2)
{
	int	cmp;

	cmp = node1->key_length - node2->key_length;
	if (cmp != 0)
		return (-cmp);
	return (ft_strcmp(node1->key, node2->key));
}

t_dict_node		*ft_sorted_dict_insert_search(
					t_dict *dict,
					t_dict_node *new_node)
{
	int			cmp;
	t_dict_node *pos;
	t_dict_node *prev;

	pos = dict->head;
	prev = NULL;
	while (pos != NULL)
	{
		cmp = ft_dict_cmp(pos, new_node);
		if (cmp == 0)
		{
			dict->error = "Duplicate key";
			return (NULL);
		}
		if (cmp > 0)
		{
			new_node->next = pos;
			break ;
		}
		prev = pos;
		pos = pos->next;
	}
	return (prev);
}

int				ft_sorted_dict_insert(t_dict *dict, char *key, char *value)
{
	t_dict_node *node;
	t_dict_node *new_node;

	if (dict->error)
		return (0);
	new_node = ft_create_dict_node(key, value);
	if (new_node == NULL)
	{
		dict->error = "New node allocation error";
		return (0);
	}
	node = ft_sorted_dict_insert_search(dict, new_node);
	dict->size += 1;
	if (node == NULL)
		dict->head = new_node;
	else
		node->next = new_node;
	return (dict->error == NULL);
}

char			*ft_dict_get_value(t_dict *dict, char *key)
{
	t_dict_node	*node;

	node = dict->head;
	while (node != NULL)
	{
		if (ft_strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (0);
}
