/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:30:31 by hstander          #+#    #+#             */
/*   Updated: 2017/06/09 16:14:05 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizen(char const *s, char c)
{
	int chr;
	int str;
	int i;

	i = 0;
	chr = 0;
	str = 0;
	while (s[i])
	{
		if (s[i] != c)
			str++;
		if (s[i] == c && str > 0)
		{
			chr++;
			str = 0;
		}
		i++;
	}
	if (s[i] == '\0' && str > 0)
		chr++;
	return (chr);
}

static int	ft_len(char const *s, int start, char c)
{
	int i;

	i = 0;
	while (s[start] != c && s[start] != '\0')
	{
		i++;
		start++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if ((ptr = (char **)malloc(sizeof(char *) * (ft_sizen(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			if (s[i] == '\0')
				break ;
			ptr[j++] = ft_strsub(s, i, ft_len(s, i, c));
			i += ft_len(s, i, c);
		}
	}
	ptr[j] = NULL;
	return (ptr);
}
