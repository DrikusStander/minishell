/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:09:41 by hstander          #+#    #+#             */
/*   Updated: 2017/07/28 11:23:12 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(char **args, t_f_str *fs)
{
	int		i;

	i = 1;
	while (args[i])
	{
		if (i > 1)
		{
			ft_putchar(' ');
			if (ft_strncmp(args[i], "$", 1) == 0 && ft_strlen(args[i]) > 1)
				echo_env(args[i], fs);
			else
				ft_putstr(args[i]);
		}
		else
		{
			if (ft_strncmp(args[i], "$", 1) == 0 && ft_strlen(args[i]) > 1)
				echo_env(args[i], fs);
			else
				ft_putstr(args[i]);
		}
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int		echo_env(char *arg, t_f_str *fs)
{
	int		i;
	char	*ptr;

	i = 0;
	arg++;
	if ((i = ft_checkvar(arg, fs)) > -1)
	{
		ptr = ft_strchr(fs->envp[i], '=');
		ptr++;
		ft_putstr(ptr);
		return (1);
	}
	return (0);
}

int		ft_exit(char **args, t_f_str *fs)
{
	int i;

	i = 0;
	(void)args;
	ft_free2d(fs->envp);
	ft_free2d(fs->f_str);
	return (0);
}

int		ft_cd(char **args, t_f_str *fs)
{
	if (args[1] == NULL)
		ch_home(fs);
	else if (ft_strncmp(args[1], "~", 1) == 0)
		ch_tilda(args[1], fs);
	else if (ft_strcmp(args[1], "-") == 0)
		ch_oldpwd(fs);
	else
	{
		if (chdir(args[1]) != 0)
			ft_putstr_fd("cd: no such file or directory\n", 2);
		else
			set_pwd(fs);
	}
	return (1);
}
