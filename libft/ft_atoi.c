/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:53:14 by hstander          #+#    #+#             */
/*   Updated: 2017/06/08 17:51:28 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned long	res;
	unsigned long	test;

	test = 0;
	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		i++;
	neg = (str[i] == '-' ? -1 : 1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		test = res;
		res = res * 10 + (str[i] - '0');
		i++;
		if (res < test)
			return (neg < 0 ? 0 : -1);
	}
	return (res * neg);
}
