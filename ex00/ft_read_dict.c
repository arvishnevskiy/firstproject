/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:37:00 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 19:54:26 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "ft_rush.h"

int		ft_parse_dict_buf(t_dict *dict, char *buf, int size)
{
	int		pos;
	int		diff;
	int		parsed_count;

	pos = 0;
	while (pos < size)
	{
		parsed_count = ft_parse_dict_record(dict, buf + pos, size - pos);
		if (dict->error)
			return (-1);
		if (parsed_count == 0)
			break ;
		pos += parsed_count;
	}
	diff = size - pos;
	if (diff < 0)
		dict->error = "PARSING OVERFLOW!";
	else if (diff > 0)
		ft_memcpy(buf, buf + pos, diff);
	return (diff);
}

void	ft_read_dict(int handle, t_dict *dict)
{
	int		size;
	int		pos;
	char	*buf;

	buf = malloc(sizeof(char) * FILE_BUF_SIZE);
	if (buf == NULL)
	{
		dict->error = "Failed to alloc memory for file";
		return ;
	}
	pos = 0;
	while ((size = read(handle, buf + pos, FILE_BUF_SIZE - pos)))
	{
		pos = ft_parse_dict_buf(dict, buf, size + pos);
		if (pos < 0)
			break ;
	}
	free(buf);
}

t_dict	*ft_parse_dict(char *fname)
{
	t_dict			*dict;
	int				handle;
	int				size;

	dict = ft_create_dict();
	if (!dict)
		return (NULL);
	handle = open(fname, O_RDONLY);
	if (handle == -1)
	{
		dict->error = "File open error";
		return (dict);
	}
	size = read(handle, 0, 0);
	if (size == -1)
	{
		dict->error = "Is directory";
		return (dict);
	}
	ft_read_dict(handle, dict);
	close(handle);
	return (dict);
}
