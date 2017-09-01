/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:29:18 by hstander          #+#    #+#             */
/*   Updated: 2017/08/18 12:28:47 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_execute(char **args, t_func *fc, t_f_str *fs)
{
	int i;

	i = 0;
	if (args[0] == NULL || ft_strlen(args[0]) == 0)
		return (1);
	while (fs->f_str[i])
	{
		if (ft_strcmp(args[0], fs->f_str[i]) == 0)
			return (fc->builtin_func[i](args, fs));
		i++;
	}
	return (ft_launch(args, fs, fc));
}

void	ft_trim(char **line)
{
	char *temp;

	if (line != NULL)
	{
		temp = ft_strtrim(*line);
		free(*line);
		*line = temp;
	}
}

void	loop(t_func *fc, t_f_str *fs)
{
	char	*line;
	char	**args;
	int		status;

	line = NULL;
	args = NULL;
	status = 44;
	while (status)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		ft_trim(&line);
		args = ft_split(line, ' ');
		status = ft_execute(args, fc, fs);
		if (args != NULL)
			ft_free2d(args);
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
	}
}
