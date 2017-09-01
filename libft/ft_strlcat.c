/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 06:45:37 by hstander          #+#    #+#             */
/*   Updated: 2017/06/09 07:50:44 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	dlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	n = size;
	while (n-- != 0 && dest[i] != '\0')
		i++;
	dlen = i;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (src[j])
	{
		if (n != 1)
		{
			dest[i++] = src[j];
			n--;
		}
		j++;
	}
	dest[i] = '\0';
	return (dlen + j);
}
