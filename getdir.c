/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 18:08:58 by hstander          #+#    #+#             */
/*   Updated: 2017/07/28 08:10:21 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_getdir(char *dir, char *needle, char *cwd)
{
	DIR				*dp;
	struct dirent	*entry;

	if ((dp = opendir(dir)) == NULL)
		return (0);
	chdir(dir);
	while ((entry = readdir(dp)) != NULL)
	{
		if (ft_strcmp(entry->d_name, needle) == 0)
		{
			chdir(cwd);
			closedir(dp);
			return (1);
		}
	}
	chdir(cwd);
	closedir(dp);
	return (0);
}
