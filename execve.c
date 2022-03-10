/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:52:03 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 17:05:37 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

char	**parse_paths(char **envp)
{
	char	**paths;
	char	*str;
	int		i;

	i = 0;
	str = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
	while (str == NULL)
	{
		i++;
		str = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
	}
	str = ft_substr(str, 6, ft_strlen(str));
	paths = ft_split(str, ':');
	i = 0;
	while (paths[i] != NULL)
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	free(str);
	return (paths);
}

void	exec_cmd(char *line, char **envp)
{
	char	**paths;
	int		i;
	char	**args;
	char	*cmd;

	args = ft_split(line, ' ');
	(void)line;
	paths = parse_paths(envp);
	i = 0;
	while (paths[i])
	{
		cmd = ft_strjoin(paths[i], args[0]);
		execve(cmd, args, envp);
		i++;
	}
	access(cmd, R_OK);
	perror(args[0]);
}
