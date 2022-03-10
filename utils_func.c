/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:30:21 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 10:47:02 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

// Function to update pwd IN ENV -> after make cd (chdir), which one don't update ENV
void	update_pwd(t_data *data) //check for leaks
{
	int		i;
	char	*temp;
	char	*path;

	(void)data;
	i = 0;
	path = ft_strjoin("PWD=", get_pwd(data));
	if (!path)
		exit(0);
	temp = NULL;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PWD=", 4) == 0)
		{
			temp = ft_strdup(data->env[i]);
			data->env[i] = path;
			if (temp)
				free(temp);
			return ;
		}
		i++;
	}
	if (path)
		free(path);
	if (temp)
		free(temp);
}
