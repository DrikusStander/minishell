/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 07:05:12 by hstander          #+#    #+#             */
/*   Updated: 2017/08/15 08:21:07 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fork(char **args, char *ptr, t_f_str *fs)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		execve(ptr, args, fs->envp);
		exit(-1);
	}
	else if (pid < 0)
		ft_putstr_fd(" : error forking\n", 2);
	else
	{
		WIFEXITED(status);
		wait(&status);
	}
}

void	ft_error(t_f_str *fs, char **args)
{
	if (fs->path != NULL)
		ft_free2d(fs->path);
	free(fs->cwd);
	ft_putstr_fd("minishell: command not found ", 2);
	ft_putstr_fd(args[0], 2);
	ft_putchar_fd('\n', 2);
}

int		ft_launch(char **args, t_f_str *fs, t_func *fc)
{
	char	*ptr;
	int		acc;

	acc = -2;
	(void)fc;
	ft_pwd(fs);
	ft_path(fs);
	if (!fs->path && ft_strchr(args[0], '/') == NULL)
		ptr = NULL;
	else
		ptr = ft_validate(args, fs, &acc);
	if (ptr != NULL)
	{
		ft_fork(args, ptr, fs);
		if (ptr != NULL && acc != 0)
			free(ptr);
		free(fs->cwd);
		if (fs->path != NULL)
			ft_free2d(fs->path);
	}
	else
		ft_error(fs, args);
	return (1);
}

int		main(void)
{
	t_f_str	fs;
	t_func	fc;

	init_env(&fs);
	init_builtin(&fc, &fs);
	loop(&fc, &fs);
	return (0);
}
