/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:39:18 by hstander          #+#    #+#             */
/*   Updated: 2017/06/19 16:07:23 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1len;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	s1len = ft_strlen(s1);
	if ((ptr = (char *)malloc(s1len + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[s1len + i] = s2[i];
		i++;
	}
	ptr[s1len + i] = '\0';
	return (ptr);
}
