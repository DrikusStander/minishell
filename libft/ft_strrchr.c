/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:46:36 by hstander          #+#    #+#             */
/*   Updated: 2017/06/09 07:58:14 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;
	int		slen;

	slen = ft_strlen(s);
	i = (char *)s + slen;
	while (*i != c)
	{
		if (i == s)
		{
			return (NULL);
		}
		i--;
	}
	return (i);
}
