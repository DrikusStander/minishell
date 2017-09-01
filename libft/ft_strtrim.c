/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:57:13 by hstander          #+#    #+#             */
/*   Updated: 2017/06/10 13:43:41 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	int		slen;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	slen = ft_strlen(s);
	while (s[j] == '\t' || s[j] == '\n' || s[j] == ' ')
		j++;
	slen--;
	while ((s[slen] == '\t' || s[slen] == '\n' || s[slen] == ' ') && j < slen)
		slen--;
	if ((ptr = (char *)malloc(sizeof(char) * (slen - j + 2))) == NULL)
		return (NULL);
	while (j <= slen)
	{
		ptr[i] = s[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
