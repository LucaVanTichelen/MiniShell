/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:30:25 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/03/10 10:30:26 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms.h"

static int	ft_word_count(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			n++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (n);
}

static int	ft_letter_count(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		n++;
	}
	return (n);
}

static void	ft_mem_free(char **s, size_t n)
{
	while (n >= 0)
	{
		free(s[n]);
		s[n] = NULL;
		n--;
	}
	free(s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;
	size_t	n;

	result = NULL;
	n = 0;
	count = 0;
	if (!(s))
		return (0);
	count = ft_word_count(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!(result))
		return (0);
	while (*s && n < count)
	{
		while (*s != '\0' && *s == c)
			s++;
		result[n] = ft_substr(s, 0, ft_letter_count(s, c));
		if (!(result[n]))
			ft_mem_free(result, n);
		n++;
		s = s + ft_letter_count(s, c);
	}
	result[n] = NULL;
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

char	*ft_strdup(const char *src)
{
	size_t	n;
	char	*src1;
	char	*copy;

	src1 = (char *)src;
	n = ft_strlen(src);
	copy = (char *)malloc(n + 1);
	if (copy == NULL)
		return (0);
	ft_strlcpy(copy, src1, n + 1);
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char *)malloc(len + 1);
		if (!(new))
			return (NULL);
		while (*s1 != '\0')
		{
			*new = *s1;
			new++;
			s1++;
		}
		while (*s2 != '\0')
			*new++ = *s2++;
		*new = '\0';
		new -= len;
	}
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	m;

	if (!dst || !src)
		return (0);
	m = ft_strlen(src);
	n = size;
	if (size)
		size -= 1;
	while (size && *src)
	{
		*(dst++) = *(src++);
		size--;
	}
	if (n)
		*dst = '\0';
	return (m);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*n1;
	char	*n2;

	n1 = (char *)s1;
	n2 = (char *)s2;
	if (n == 0)
		return (0);
	n = n - 1;
	while (*n1 == *n2 && n > 0 && *n1)
	{
		n1++;
		n2++;
		n--;
	}
	return ((unsigned char)*n1 - (unsigned char)*n2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = NULL;
	if (!s)
		return (0);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	if (start < ft_strlen(s))
	{
		s = s + start;
		while (*s && i < len)
		{
			sub[i] = *s;
			s++;
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
