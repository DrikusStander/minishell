/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:30:31 by hstander          #+#    #+#             */
/*   Updated: 2017/07/28 14:52:36 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

void		ft_space(char const *s, t_split *sp, int *i)
{
	while (s[*i] && s[*i] != sp->c)
	{
		if (s[*i] == '\t')
			break ;
		*i += 1;
	}
}

static void	ft_sizen(char const *s, t_split *sp)
{
	int i;

	i = 0;
	while (s[i])
	{
		while (s[i] == sp->c || s[i] == '\t')
			i++;
		if (s[i] == '"')
		{
			ft_skip(s, &i, '"');
			while (s[i] && s[i] != '"')
				i++;
			if (s[i] == '\0')
				break ;
			i++;
			sp->chr++;
		}
		else
		{
			ft_skip2(s, &i, sp->c);
			ft_space(s, sp, &i);
			sp->chr++;
		}
	}
}

void		ft_qsplit(char const *s, char **ptr, t_split *sp)
{
	int k;
	int len;

	len = ft_strlen(s);
	k = 0;
	ptr[sp->j] = (char *)ft_memalloc(sizeof(char) * (len + 1));
	while (s[sp->i] == '"')
		sp->i++;
	while (s[sp->i] != '"' && s[sp->i])
	{
		ptr[sp->j][k] = s[sp->i];
		k++;
		sp->i++;
	}
}

void		ft_csplit(char const *s, char **ptr, t_split *sp)
{
	int k;
	int len;

	len = ft_strlen(s);
	k = 0;
	ptr[sp->j] = (char *)ft_memalloc(sizeof(char) * (len + 1));
	while (s[sp->i] != sp->c && s[sp->i])
	{
		if (s[sp->i] == '\t')
			break ;
		ptr[sp->j][k] = s[sp->i];
		k++;
		sp->i++;
	}
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	t_split	sp;

	ft_bzero(&sp, sizeof(t_split));
	sp.c = c;
	ft_sizen(s, &sp);
	if (s == NULL)
		return (NULL);
	if ((ptr = (char **)ft_memalloc(sizeof(char *) * (sp.chr + 1))) == NULL)
		return (NULL);
	while (s[sp.i] && sp.j < sp.chr)
	{
		while (s[sp.i] == c || s[sp.i] == '\t')
			sp.i++;
		if (s[sp.i] == '"')
			ft_qsplit(s, ptr, &sp);
		else
			ft_csplit(s, ptr, &sp);
		sp.j++;
		if (s[sp.i] == '\0')
			break ;
		sp.i++;
	}
	return (ptr);
}
