/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:44:25 by hstander          #+#    #+#             */
/*   Updated: 2017/06/19 17:07:30 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	if ((ptr = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	ft_memcpy(ptr, s, len + 1);
	return (ptr);
}
