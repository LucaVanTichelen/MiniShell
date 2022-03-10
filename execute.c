/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:51:04 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 17:05:21 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

void	make_dollar(t_data *data, char *key)
{
	char	*value;
	int		i = 0;

	while (data->env_now[i])
	{
		if (ft_strncmp(data->env_now[i], key, ft_strlen(key)) == 0)
		{
			value = value_from_line(data->env_now[i]);
			printf("%s\n", value);
		}
		i++;
	}
}

void	handle_sig(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_on_new_line();
		// rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		exit (1);
	}
}

void	execute(t_data *data)
{
	int		i;
	char	**splited;
	int		pid;

	i = 0;
	while (data->strstr[i])
	{
		signal(SIGINT, handle_sig);
		signal(SIGQUIT, SIG_IGN);
		splited = ft_split(data->strstr[i], ' ');
		if (strcmp(splited[0],"pwd") == 0)
			printf("%s\n", get_pwd(data));
		else if (strcmp(data->strstr[i], "env") == 0)
			print_env(data);
		else if (strcmp(splited[0], "cd") == 0)
			make_cd(data, splited);
		else if (strcmp(splited[0], "echo") == 0)
			make_echo(data->strstr[i]);
		else if (strcmp(splited[0], "exit") == 0)
			make_exit();
		else if (strcmp(splited[0], "export") == 0)
			try_export(data, splited[1]);
		else if (strcmp(splited[0], "unset") == 0)
			try_unset(data, splited[1]);
		else if (data->strstr[i][0] == '$')
			make_dollar(data, data->strstr[i] + 1);
		else
		{
			pid = fork();
			if (pid == 0)
				exec_cmd(data->strstr[i], data->env_now);
			else
				waitpid(pid, NULL, 0);
		}
		i++;
	}
}
