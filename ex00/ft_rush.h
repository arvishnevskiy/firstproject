/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:10:54 by delyn             #+#    #+#             */
/*   Updated: 2021/02/07 20:36:35 by delyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <stdlib.h>
# include "ft.h"

# define FILE_BUF_SIZE (16 * 1024)
# define ENABLE_VERBOSE_ERRORS 0

typedef struct	s_nbr
{
	unsigned int	length;
	char			*value;
}				t_nbr;

typedef struct	s_dict_node
{
	unsigned int		key_length;
	char				*key;
	char				*value;
	struct s_dict_node	*next;
}				t_dict_node;

typedef struct	s_dict
{
	unsigned int		size;
	char				*error;
	struct s_dict_node	*head;
}				t_dict;

typedef struct	s_match
{
	char		*value;
	int			replace_count;
	char		*key;
	int			key_length;
}				t_match;

typedef struct	s_word
{
	char			*value;
	int				size;
	struct s_word	*next;
}				t_word;

void			ft_echo(char *fname);
t_dict			*ft_parse_dict(char *fname);
char			*ft_ignore_spaces(char *str);
t_nbr			*ft_parse_number(char *str);
t_dict			*ft_create_dict(void);
t_dict_node		*ft_create_dict_node(char *key, char *value);
int				ft_dict_cmp(t_dict_node *node1, t_dict_node *node2);
void			ft_dict_clear(t_dict *dict);
int				ft_sorted_dict_insert(t_dict *dict, char *key, char *value);
int				ft_parse_dict_record(t_dict *dict, char *buf, int length);
t_word			*ft_dict_match(t_dict *dict, t_nbr *nbr);
int				ft_words_push_front(t_word **begin_list, char *value, int size);
void			ft_words_clear(t_word *word);
char			*ft_dict_get_value(t_dict *dict, char *key);
int				ft_words_replace(t_word **begin_list, char *value, int count);
t_match			*ft_create_match(char *key, int key_length);

void			ft_log_error(char *error, char *verbose_error);
void			ft_print_words(t_word *node);

char			*ft_dm_get_scale(t_dict *dict, char *nbr, int length);
int				ft_dm_get_scale_replace_count(char *value,
					char *nbr, int length);
int				ft_dm_is_scale(t_dict *dict, char *nbr, int length);
void			ft_dm_add_scale(t_dict *dict, t_word **word,
					char *nbr, int level);
void			ft_dm_add_value(t_dict *dict, t_word **word,
					t_match *match, char *nbr);

int				ft_dict_is_space(char c);
int				ft_dict_is_printable(char c);
void			ft_dict_search_value_start(char **buf, int *length);
void			ft_skip_spaces(char **buf, int *length);
void			ft_parse_dict_number_skip(char **buf, int *length);
char			*ft_parse_dict_strdup(char *str, int length);
int				ft_parse_dict_number(char **buf, int *length, char **nbr);
int				ft_parse_dict_value_help(char **buf, int *length, char **value);
#endif
