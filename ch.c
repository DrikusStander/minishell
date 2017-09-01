/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 09:55:43 by hstander          #+#    #+#             */
/*   Updated: 2017/07/28 09:58:30 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ch_tilda(char *arg, t_f_str *fs)
{
	int		i;
	char	*temp[3];

	i = 0;
	arg++;
	if ((i = ft_checkvar("HOME", fs)) > -1)
	{
		temp[1] = ft_strchr(fs->envp[i], '/');
		temp[1] = ft_strjoin(temp[1], arg);
		ft_cd(temp, fs);
		free(temp[1]);
	}
}

void	ch_oldpwd(t_f_str *fs)
{
	char	*ptr[3];
	int		i;

	i = 0;
	if ((i = ft_checkvar("OLDPWD", fs)) > -1)
	{
		ptr[1] = ft_strchr(fs->envp[i], '/');
		ft_cd(ptr, fs);
	}
}

void	ch_home(t_f_str *fs)
{
	char	*ptr[3];
	int		i;

	i = 0;
	if ((i = ft_checkvar("HOME", fs)) > -1)
	{
		ptr[1] = ft_strchr(fs->envp[i], '/');
		ft_cd(ptr, fs);
	}
}
