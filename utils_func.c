/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:13:26 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 17:15:11 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

// Function to update pwd IN ENV -> after make cd (chdir), which one don't update ENV
void	update_pwd(t_data *data) //check for leaks
{
	int		i;
	char	*temp;
	char	*path;

	i = 0;
	(void)data;
	path = ft_strjoin("PWD=", get_pwd());
	if (!path)
		exit(0);
	temp = NULL;
	while (data->env_now[i])
	{
		if (ft_strncmp(data->env_now[i], "PWD=", 4) == 0)
		{
			temp = ft_strdup(data->env_now[i]);
			data->env_now[i] = path;
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

// return line in env with *str
char	*line_in_env(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (data->env_now[i])
	{
		if (ft_strncmp(data->env_now[i], str, ft_strlen(str)) == 0)
			return (data->env_now[i]);
		i++;
	}
	return (NULL);
}

// return VALUE from line (by =)
char	*value_from_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '=')
		i++;
	return (ft_substr(line, i + 1, ft_strlen(line) - i));
}
