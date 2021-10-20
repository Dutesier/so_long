/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:21:02 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/15 17:00:01 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	char	*d;

	d = (char *)s;
	while (*d != '\0')
	{
		if (*d == (char)c)
			return (d);
		d++;
	}
	if (*d == (char)c)
		return (d);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*s2;

	i = ft_strlen(s1);
	l = 0;
	s2 = malloc(i + 1);
	if (!s2)
		return (NULL);
	while (s1[l] != '\0')
	{
		s2[l] = s1[l];
		l++;
	}
	s2[l] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		j;
	int		s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = (int)ft_strlen(s);
	if (len > s_len)
		sub = malloc(ft_strlen(s) + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	j = 0;
	while (j < len && s[start] && (int)start < s_len)
	{
		sub[j] = s[start];
		start++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
