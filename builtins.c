/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:50:44 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 16:59:58 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

char	*get_pwd(t_data *data)
{
	return (getcwd(data->buff, sizeof(data->buff)));
}

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env_now[i])
		printf("%s\n", data->env_now[i++]);
}

void	make_cd(t_data *data, char **av)
{
	int		count;
	char	*line;
	char	*home;

	count = size_of_double(av);
	if (count == 2)
	{
		if (ft_strncmp(av[1], "~", 1) == 0)
			count = -1;
		else
		{
			chdir(av[1]);
			update_pwd(data);
		}
	}
	if (count == 1 || count == -1)
	{
		line = line_in_env(data, "HOME=");
		home = value_from_line(line);
		chdir(home);
		update_pwd(data);
	}
	if (count > 2)
	{
		printf("error -> to many arguments\n");
	}
}

//garbage function to change
int	found_n(char *str)
{
	if (str[5] && str[6] && str[5] == '-' && str[6] == 'n')
		return (1);
	return (0);
}

void	make_echo(char *str)
{
	char	*send;

	if (found_n(str))
	{
		send = ft_strdup(str + 8);
		printf("%s", send);
	}
	else
	{
		send = ft_strdup(str + 5);
		printf("%s\n", send);
	}
	//free(send);
}

void	make_exit(void)
{
	exit(0);
}

void	make_notfound(char *str)
{
	printf(">: %s: command not found\n", str);
}
