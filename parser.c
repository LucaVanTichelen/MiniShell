/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:10:57 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 17:12:41 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

int	find_divider(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (i);
		i++;
	}
	return (i);
}

int	need_to_divide(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

void	fill_strstr(t_data *data, char *str)
{
	int	to_malloc;
	int	i;
	int	start;
	int	len;

	i = 0;
	start = 0;
	len = 0;
	to_malloc = need_to_divide(str);
	data->strstr = malloc(sizeof(char *) * (to_malloc + 1 + 1));
	while (i < to_malloc + 1)
	{
		len = find_divider(str + start);
		data->strstr[i] = ft_substr(str, start, len);
		start += len + 1;
		i++;
	}
	data->strstr[i] = NULL;
}

void	parce(t_data *data)
{
	char	*str;

	str = readline("> :");
	add_history(str);
	fill_strstr(data, str);
}
