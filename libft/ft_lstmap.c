/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:08:38 by hstander          #+#    #+#             */
/*   Updated: 2017/06/09 14:17:47 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new;
	t_list	*temp;

	if ((start = f(lst)) == NULL)
		return (NULL);
	lst = lst->next;
	new = start;
	while (lst != NULL)
	{
		temp = new;
		if ((new = f(lst)) == NULL)
			return (NULL);
		temp->next = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (start);
}
