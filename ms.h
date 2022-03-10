/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:07:12 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 17:10:42 by lvan-tic         ###   ########.fr       */
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
# include <signal.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_cmd
{
	char			**arg;
	t_list			*lst;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	int		num;
	t_cmd	*cmds;
	char	**env;
	char	buff[PATH_MAX];
	char	**env_temp;
	char	**env_now;
	int		env_i;
	char	**strstr; //strstr[0], strstr[1] = NULL;
}	t_data;

//builtins
char	*get_pwd(void);
void	print_env(t_data *data);
void	make_cd(t_data *data, char **av);
void	make_echo(char *str);

void	make_exit(void);
void	make_notfound(char *str);

//utils_func.c
void	update_pwd(t_data *data); //TO DO -> check for leaks
char	*line_in_env(t_data *data, char *str);
char	*value_from_line(char *line);

// utils
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

//env.c
void	try_export(t_data *data, char *str);
char	**env_plus_line(t_data *data, char *line);
int		index_line_env(t_data *data, char *line);
char	**env_minus_line(t_data *data, char *line);
char	**envp_copy(char **envp);
int		size_of_double(char **env_now);
void	try_unset(t_data *data, char *str);

//lst_utils.c
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstlast(t_list	*lst);
t_list	*ft_lstnew(char *content);
size_t	ft_lstsize(t_list *lst);

void	parce(t_data *data);
void	execute(t_data *data);
void	exec_cmd(char *line, char **envp);

#endif
