/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:30:18 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 10:38:41 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_H
# define MS_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<readline/readline.h>
# include	<readline/history.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	char	**env;
	char	buff[PATH_MAX];
}	t_data;

//builtins
char	*get_pwd(t_data *data);
void	print_env(char **env);
void	make_cd(t_data *data, char *str);
void	make_echo(char *str);
void	make_exit(void);
void	make_notfound(char *str);

//utils_func.c
void	update_pwd(t_data *data); //TO DO -> check for leaks

// utils
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
