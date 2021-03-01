/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delyn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:31:38 by delyn             #+#    #+#             */
/*   Updated: 2021/02/11 14:18:21 by kelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void			ft_putstr(char *str);
void			ft_puts(char *str);
void			ft_error(char *str);
void			ft_putnbr(int nb);
unsigned int	ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
void			ft_memcpy(char *dst, char *src, unsigned int size);
int				ft_memcmp(char *s1, char *s2, unsigned int size);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_concat(char *s1, char *s2);
#endif
