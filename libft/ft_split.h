/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:55:30 by hstander          #+#    #+#             */
/*   Updated: 2017/07/28 14:52:17 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H
# include "libft.h"

typedef struct	s_split
{
	int			i;
	int			j;
	char		c;
	int			chr;
}				t_split;

void			ft_skip(char const *s, int *i, char c);
void			ft_skip2(char const *s, int *i, char c);

#endif
