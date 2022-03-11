/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:06:07 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/11 11:35:34 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

void	while_loop(t_data *data)
{
	while (1)
	{
		parce(data);
		execute(data);
	}
}

void	init_data(t_data *data, char **envp, t_cmd *cmds)
{
	data->env_now = envp_copy(envp);
	data->cmds = cmds;
}

void	signal_cmd(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;

	(void)argc;
	(void)argv;
	(void)envp;
	signal(SIGINT, signal_cmd);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str = readline("minishell$> ");
		add_history(str);
		signal(SIGINT, signal_cmd);
		signal(SIGQUIT, SIG_IGN);
		if (str == NULL)
		{
			printf("\x1b[1A\033[12Cexit\n");
			return (1);
		}
		free(str);
	}
}
