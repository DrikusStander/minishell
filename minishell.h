/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 09:06:39 by hstander          #+#    #+#             */
/*   Updated: 2017/07/28 11:34:31 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/param.h>

typedef struct	s_f_str
{
	char		**envp;
	int			f_num;
	char		**f_str;
	char		**path;
	char		*cwd;
}				t_f_str;

typedef struct	s_func
{
	int			(*builtin_func[7])(char **, t_f_str *);
}				t_func;

int				ft_getdir(char *dir, char *needle, char *cwd);
int				ft_echo(char **args, t_f_str *fs);
int				ft_exit(char **args, t_f_str *fs);
int				ft_cd(char **args, t_f_str *fs);
int				ft_env(char **args, t_f_str *fs);
void			init_env(t_f_str *fs);
void			init_builtin(t_func *fc, t_f_str *fs);
int				ft_execute(char **args, t_func *fc, t_f_str *fs);
void			loop(t_func *fc, t_f_str *fs);
int				ft_launch(char **args, t_f_str *fs, t_func *fc);
int				ft_checkvar(char *arg, t_f_str *fs);
void			ft_addvar(t_f_str *fs, char *var);
int				ft_setenv(char **args, t_f_str *fs);
int				ft_unsetenv(char **args, t_f_str *fs);
void			ch_home(t_f_str *fs);
void			ch_oldpwd(t_f_str *fs);
void			ch_tilda(char *arg, t_f_str *fs);
void			set_pwd(t_f_str *fs);
int				echo_env(char *arg, t_f_str *fs);
void			ft_pwd(t_f_str *fs);
void			ft_path(t_f_str *fs);
char			*ft_validate(char **args, t_f_str *fs, int *acc);
void			ft_fork(char **args, char *ptr, t_f_str *fs);
void			ft_error(t_f_str *fs, char **args);
void			set_pwd(t_f_str *fs);
char			*ft_validpath(t_f_str *fs, char **args, int i);

#endif
