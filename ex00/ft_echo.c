/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:27:30 by delyn             #+#    #+#             */
/*   Updated: 2021/02/11 14:28:07 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

t_nbr	*ft_echo_read_nbr(void)
{
	char	*buf;
	int		size;
	t_nbr	*nbr;

	buf = malloc(sizeof(char) * FILE_BUF_SIZE);
	if (!buf)
		return (NULL);
	while ((size = read(0, buf, FILE_BUF_SIZE)))
	{
		buf[size - 1] = 0;
		nbr = ft_parse_number(buf);
		if (nbr == NULL)
		{
			ft_log_error("Error", "Invalid number value");
			continue ;
		}
		free(buf);
		return (nbr);
	}
	free(buf);
	return (NULL);
}

void	ft_echo(char *fname)
{
	t_dict	*dict;
	t_word	*word;
	t_nbr	*nbr;

	dict = ft_parse_dict(fname);
	if (dict->error)
		ft_log_error("Dict Error", dict->error);
	else
	{
		while ((nbr = ft_echo_read_nbr()))
		{
			dict->error = NULL;
			word = ft_dict_match(dict, nbr);
			if (dict->error)
				ft_log_error("Dict Error", dict->error);
			else
				ft_print_words(word);
			ft_words_clear(word);
			free(nbr);
		}
	}
	ft_dict_clear(dict);
}
