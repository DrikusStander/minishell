/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:04:12 by hstander          #+#    #+#             */
/*   Updated: 2017/06/09 07:52:10 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nsize(int n)
{
	int i;

	i = 0;
	while (n <= 0 || n >= 0)
	{
		n = n / 10;
		i++;
		if (n == 0)
			break ;
	}
	return (i);
}

void			ft_putnbr(int n)
{
	char	num1[22];
	long	num;
	int		i;

	num = n;
	i = ft_nsize(n);
	num1[i] = '\0';
	i--;
	if (num < 0)
	{
		ft_putchar('-');
		num = num * -1;
	}
	while (i >= 0)
	{
		num1[i] = '0' + (num % 10);
		num = num / 10;
		i--;
	}
	ft_putstr(num1);
}
