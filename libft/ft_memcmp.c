/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:43:37 by hstander          #+#    #+#             */
/*   Updated: 2017/06/09 07:49:47 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	int					res;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	i = 0;
	res = 0;
	ss1 = s1;
	ss2 = s2;
	while (i < n)
	{
		res = ss1[i] - ss2[i];
		if (res != 0)
		{
			return (res);
		}
		i++;
	}
	return (res);
}
