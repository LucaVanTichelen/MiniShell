/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:30:05 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 10:32:22 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

char	*get_pwd(t_data *data)
{
	return (getcwd(data->buff, sizeof(data->buff)));
}

void	print_env(char **env)
{
	while (*env)
		printf("%s\n", *env++);
}

void	make_cd(t_data *data, char *str)
{
	chdir(str);
	update_pwd(data);
}

void	make_echo(char *str)
{
	printf("%s\n", str);
}

void	make_exit(void)
{
	exit(0);
}

void	make_notfound(char *str)
{
	printf(">: %s: command not found\n", str);
}
