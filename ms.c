/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:06:07 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 17:06:55 by lvan-tic         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	t_cmd	*cmds;

	data = (t_data *)calloc(1, sizeof(t_data));
	cmds = (t_cmd *)calloc(1, sizeof(t_cmd));
	init_data(data, envp, cmds);
	(void)argv;
	(void)argc;
	while_loop(data);
}
