/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:33:09 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 20:35:58 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"
#include "ft_test.h"

#define ENABLE_VERBOSE_ERRORS 0

void	ft_log_error(char *error, char *verbose_error)
{
	ft_puts(error);
	if (ENABLE_VERBOSE_ERRORS)
	{
		ft_puts(verbose_error);
	}
}

void	ft_convert_number(char *str, char *fname)
{
	t_nbr	*nbr;
	t_dict	*dict;
	t_word	*word;

	nbr = ft_parse_number(str);
	if (nbr == NULL)
	{
		ft_log_error("Error", "Invalid number value");
		return ;
	}
	dict = ft_parse_dict(fname);
	if (dict->error)
		ft_log_error("Dict Error", dict->error);
	else
	{
		word = ft_dict_match(dict, nbr);
		if (dict->error)
			ft_log_error("Dict Error", dict->error);
		else
			ft_print_words(word);
		ft_words_clear(word);
	}
	free(nbr);
	ft_dict_clear(dict);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_echo("numbers.dict");
		return (0);
	}
	if (argc > 3)
	{
		ft_log_error("Error", "Too many arguments");
		return (1);
	}
	if (argc == 2)
	{
		ft_convert_number(argv[1], "numbers.dict");
	}
	else if (argc == 3)
	{
		ft_convert_number(argv[2], argv[1]);
	}
	return (0);
}
