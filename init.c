/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:25:11 by hstander          #+#    #+#             */
/*   Updated: 2017/07/17 17:00:23 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_f_str *fs)
{
	extern char **environ;
	int			i;

	i = 0;
	while (environ[i])
		i++;
	fs->envp = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = -1;
	while (environ[++i])
		fs->envp[i] = ft_strdup(environ[i]);
	ch_home(fs);
}

void	init_builtin(t_func *fc, t_f_str *fs)
{
	fs->f_num = 7;
	fc->builtin_func[0] = &ft_cd;
	fc->builtin_func[1] = &ft_exit;
	fc->builtin_func[2] = &ft_echo;
	fc->builtin_func[3] = &ft_env;
	fc->builtin_func[4] = &ft_setenv;
	fc->builtin_func[5] = &ft_unsetenv;
	fs->f_str = (char **)ft_memalloc(sizeof(char *) * fs->f_num);
	fs->f_str[0] = ft_strdup("cd");
	fs->f_str[1] = ft_strdup("exit");
	fs->f_str[2] = ft_strdup("echo");
	fs->f_str[3] = ft_strdup("env");
	fs->f_str[4] = ft_strdup("setenv");
	fs->f_str[5] = ft_strdup("unsetenv");
}
