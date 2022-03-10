/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:30:12 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 10:34:35 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

void	while_loop(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline(">: ");
		add_history(line);
		if (strcmp(line, "pwd") == 0)
			printf("%s\n", get_pwd(data));
		else if (strcmp(line, "env") == 0)
			print_env(data->env);
		else if (strcmp(line, "cd") == 0)
			make_cd(data, readline("where to cd: "));
		else if (strcmp(line, "echo") == 0)
			make_echo(readline("what to echo: "));
		else if (strcmp(line, "exit") == 0)
			make_exit();
		else if (strcmp(line, "upd") == 0)
			update_pwd(data);
		else
			make_notfound(line);
		if (line)
			free(line);
	}
}

void	init_data(t_data *data, char **envp)
{
	data->env = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = (t_data *)calloc(1, sizeof(t_data));
	init_data(data, envp);
	(void)argv;
	(void)argc;
	while_loop(data);
}
