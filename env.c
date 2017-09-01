/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:36:41 by hstander          #+#    #+#             */
/*   Updated: 2017/08/10 13:10:03 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(char **args, t_f_str *fs)
{
	int		i;

	i = 0;
	(void)args;
	while (fs->envp[i])
	{
		ft_putstr(fs->envp[i]);
		ft_putchar('\n');
		i++;
	}
	return (1);
}

int		ft_checkvar(char *arg, t_f_str *fs)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	temp = ft_strjoin(arg, "=");
	len = ft_strlen(temp);
	while (fs->envp[i])
	{
		if (ft_strncmp(fs->envp[i], temp, len) == 0)
		{
			free(temp);
			return (i);
		}
		i++;
	}
	free(temp);
	return (-1);
}

void	ft_addvar(t_f_str *fs, char *var)
{
	int		i;
	char	**new;

	i = 0;
	while (fs->envp[i])
		i++;
	new = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	i = 0;
	while (fs->envp[i])
	{
		new[i] = fs->envp[i];
		i++;
	}
	new[i] = var;
	free(fs->envp);
	fs->envp = new;
}

int		ft_setenv(char **args, t_f_str *fs)
{
	char	*var;
	char	*temp;
	int		i;

	if (args[1] == NULL)
		ft_env(args, fs);
	else if ((i = ft_checkvar(args[1], fs)) > -1)
	{
		temp = ft_strjoin(args[1], "=");
		var = ft_strjoin(temp, args[2]);
		free(fs->envp[i]);
		free(temp);
		fs->envp[i] = var;
	}
	else
	{
		temp = ft_strjoin(args[1], "=");
		var = ft_strjoin(temp, args[2]);
		free(temp);
		ft_addvar(fs, var);
	}
	return (1);
}

int		ft_unsetenv(char **args, t_f_str *fs)
{
	int		i;
	char	*temp;

	if ((i = ft_checkvar(args[1], fs)) > -1)
	{
		temp = fs->envp[i];
		while (fs->envp[i])
		{
			fs->envp[i] = fs->envp[i + 1];
			i++;
		}
		free(temp);
	}
	return (1);
}
