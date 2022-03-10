/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:30:12 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 13:36:53 by lvan-tic         ###   ########.fr       */
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

void	new_prompt(int num)
{
	(void)num;
	write(1, "\n", 1);
}

void	while_loop(t_data *data, char **envp)
{
	char	*line;
	int		pid;

	(void)data;
	while (1)
	{
		signal(SIGINT, new_prompt); // ctrl c
		// signal(SIGTSTP, SIG_IGN); // ctrl z
		signal(SIGQUIT, SIG_IGN); // ctrl backslash
		line = readline(">: ");
		add_history(line);
		// if (strcmp(line, "pwd") == 0)
		// 	printf("%s\n", get_pwd(data));
		// else if (strcmp(line, "env") == 0)
		// 	print_env(data->env);
		// else if (strcmp(line, "cd") == 0)
		// 	make_cd(data, readline("where to cd: "));
		// else if (strcmp(line, "echo") == 0)
		// 	make_echo(readline("what to echo: "));
		// else if (strcmp(line, "exit") == 0)
		// 	make_exit();
		// else if (strcmp(line, "upd") == 0)
		// 	update_pwd(data);
		// else
		// 	make_notfound(line);
		pid = fork();
		if (pid == 0)
			exec_cmd(line, envp);
		else
			waitpid(pid, NULL, 0);
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
	while_loop(data, envp);
}
