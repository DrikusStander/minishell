/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:18:25 by hstander          #+#    #+#             */
/*   Updated: 2017/06/09 07:56:50 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numsize(int n)
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

void		ft_putnbr_fd(int n, int fd)
{
	char	num1[22];
	long	num;
	int		i;

	num = n;
	i = ft_numsize(n);
	num1[i] = '\0';
	i--;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = num * -1;
	}
	while (i >= 0)
	{
		num1[i] = '0' + (num % 10);
		num = num / 10;
		i--;
	}
	ft_putstr_fd(num1, fd);
}
