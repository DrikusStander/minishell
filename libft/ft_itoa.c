/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 08:56:07 by hstander          #+#    #+#             */
/*   Updated: 2017/06/10 14:27:01 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_more(int n)
{
	char	*ptr;
	int		size;

	size = ft_size(n);
	if ((ptr = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	ptr += size;
	*ptr-- = '\0';
	while (n >= 0)
	{
		*ptr-- = '0' + (n % 10);
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (++ptr);
}

static char		*ft_less(int n)
{
	char	*ptr;
	int		size;

	size = ft_size(n);
	if ((ptr = (char *)malloc(size + 2)) == NULL)
		return (NULL);
	ptr += size + 1;
	*ptr-- = '\0';
	while (n != 0)
	{
		*ptr-- = '0' + (n % 10) * -1;
		n = n / 10;
		if (n == 0)
			break ;
	}
	*ptr = '-';
	return (ptr);
}

char			*ft_itoa(int n)
{
	char	*ptr;

	if (n >= 0)
	{
		ptr = ft_more(n);
	}
	else
	{
		ptr = ft_less(n);
	}
	return (ptr);
}
