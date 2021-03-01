/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:27:57 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 18:48:22 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_test_fill_dict_en(t_dict *dict)
{
	ft_sorted_dict_insert(dict, "0", "zero");
	ft_sorted_dict_insert(dict, "1", "one");
	ft_sorted_dict_insert(dict, "2", "two");
	ft_sorted_dict_insert(dict, "3", "three");
	ft_sorted_dict_insert(dict, "4", "four");
	ft_sorted_dict_insert(dict, "5", "five");
	ft_sorted_dict_insert(dict, "6", "six");
	ft_sorted_dict_insert(dict, "7", "seven");
	ft_sorted_dict_insert(dict, "8", "eight");
	ft_sorted_dict_insert(dict, "10", "ten");
	ft_sorted_dict_insert(dict, "11", "eleven");
	ft_sorted_dict_insert(dict, "12", "twelve");
	ft_sorted_dict_insert(dict, "13", "thirteen");
	ft_sorted_dict_insert(dict, "15", "fifteen");
	ft_sorted_dict_insert(dict, "20", "twenty");
	ft_sorted_dict_insert(dict, "30", "thirty");
	ft_sorted_dict_insert(dict, "50", "fifty");
	ft_sorted_dict_insert(dict, "54", "fifty-four");
	ft_sorted_dict_insert(dict, "100", "hundred");
	ft_sorted_dict_insert(dict, "154", "1-5-4");
	ft_sorted_dict_insert(dict, "254", "2-5-4");
	ft_sorted_dict_insert(dict, "1000", "thousand");
	ft_sorted_dict_insert(dict, "1234", "1-2-3-4");
	ft_sorted_dict_insert(dict, "12000", "lol");
	ft_sorted_dict_insert(dict, "1000000", "million");
}
