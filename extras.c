/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 09:32:56 by hstander          #+#    #+#             */
/*   Updated: 2017/08/10 13:00:00 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_f_str *fs)
{
	int		i;
	char	*temp;

	i = 0;
	fs->cwd = NULL;
	while (fs->envp[i])
	{
		if (ft_strncmp(fs->envp[i], "PWD=", 4) == 0)
		{
			temp = ft_strchr(fs->envp[i], '/');
			fs->cwd = ft_strdup(temp);
			break ;
		}
		i++;
	}
}

void	ft_path(t_f_str *fs)
{
	int		i;
	char	*temp;

	i = 0;
	fs->path = NULL;
	while (fs->envp[i])
	{
		if (ft_strncmp(fs->envp[i], "PATH=", 5) == 0)
		{
			temp = ft_strchr(fs->envp[i], '/');
			fs->path = ft_strsplit(temp, ':');
			break ;
		}
		i++;
	}
}

char	*ft_validpath(t_f_str *fs, char **args, int i)
{
	char	*temp;
	char	*ptr;

	temp = ft_strjoin(fs->path[i], "/");
	ptr = ft_strjoin(temp, args[0]);
	free(temp);
	return (ptr);
}

char	*ft_validate(char **args, t_f_str *fs, int *acc)
{
	struct stat	sb;
	int			i;
	char		*ptr;

	ptr = NULL;
	i = 0;
	if (!(!(*acc = stat(args[0], &sb)) && sb.st_mode & S_IFREG
				&& sb.st_mode & S_IXUSR))
	{
		if (fs->path == NULL)
			return (NULL);
		while (fs->path[i])
		{
			if (ft_getdir(fs->path[i], args[0], fs->cwd) == 1)
				return (ft_validpath(fs, args, i));
			i++;
		}
	}
	else
		ptr = args[0];
	return (ptr);
}

void	set_pwd(t_f_str *fs)
{
	char	*cwd;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cwd = NULL;
	cwd = getcwd(cwd, MAXPATHLEN);
	if ((i = ft_checkvar("PWD", fs)) > -1)
	{
		if ((j = ft_checkvar("OLDPWD", fs)) > -1)
		{
			temp = ft_strchr(fs->envp[i], '/');
			free(fs->envp[j]);
			fs->envp[j] = ft_strjoin("OLDPWD=", temp);
		}
		free(fs->envp[i]);
		fs->envp[i] = ft_strjoin("PWD=", cwd);
		free(cwd);
	}
}
