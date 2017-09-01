/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:04:18 by hstander          #+#    #+#             */
/*   Updated: 2017/07/24 07:52:18 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*list;

	list = *alst;
	while (list != NULL)
	{
		temp = list->next;
		del(list->content, list->content_size);
		free(list);
		list = temp;
	}
	*alst = NULL;
}
