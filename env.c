/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:51:00 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 17:03:25 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

char	**envp_copy(char **envp)
{
	char	**envp_temp;
	int		i;

	i = 0;
	envp_temp = malloc(sizeof(char *) * (size_of_double(envp) + 2));
	while (envp[i] != NULL)
	{
		envp_temp[i] = malloc(sizeof(char) * ft_strlen(envp[i]) + 1);
		ft_strlcpy(envp_temp[i], envp[i], ft_strlen(envp[i]) + 1);
		i++;
	}
	envp_temp[i] = NULL;
	return (envp_temp);
}

int	check_to_exp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	try_export(t_data *data, char *str)
{
	if (check_to_exp(str))
	{
		data->env_temp = env_plus_line(data, str);
	//free_arr(data->env_now);
		data->env_now = data->env_temp;
	}
	print_env(data);
}

void	try_unset(t_data *data, char *str)
{
	if (index_line_env(data, str) > 0)
	{
		data->env_temp = env_minus_line(data, str);
		data->env_now = data->env_temp;
	}
	print_env(data);
}

int	size_of_double(char **env_now)
{
	int	i;

	i = 0;
	while (env_now[i])
		i++;
	return (i);
}

char	**env_plus_line(t_data *data, char *line)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = malloc(sizeof(char *) * (size_of_double(data->env_now) + 2));
	if (!new_env)
		return (NULL);
	while (data->env_now[i])
	{
		new_env[i] = malloc(sizeof(char) * ft_strlen(data->env_now[i]) + 1);
		if (!new_env[i])
			return (NULL);
		ft_strlcpy(new_env[i], data->env_now[i], ft_strlen(data->env_now[i]) + 1);
		i++;
	}
	new_env[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!new_env[i])
		return (NULL);
	new_env[i] = line;
	i++;
	new_env[i] = NULL;
	return (new_env);
}

int	index_line_env(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (data->env_now[i])
	{
		if (ft_strncmp(data->env_now[i], line, ft_strlen(line)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**env_minus_line(t_data *data, char *line)
{
	int		del_line;
	char	**new_env;
	int		i = 0;
	int		j = 0;

	new_env = malloc(sizeof(char *) * size_of_double(data->env_now) + 1);
	if (!new_env)
		return (NULL);
	del_line = index_line_env(data, line);
	while (data->env_now[i])
	{
		if (i != del_line)
		{
			new_env[j] = malloc(sizeof(char) * ft_strlen(data->env_now[i]) + 1);
			if (!new_env[j])
				return (NULL);
			ft_strlcpy(new_env[j], data->env_now[i], ft_strlen(data->env_now[i]) + 1);
			j++;
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}
