/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:36:52 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 16:03:01 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_store_line(char *buff, char *holder_fd)
{
	char	*temp;

	if (holder_fd)
	{
		temp = ft_strjoin(holder_fd, buff);
		free(holder_fd);
		holder_fd = ft_strdup(temp);
		free(temp);
	}
	else
		holder_fd = ft_strdup(buff);
	return (holder_fd);
}

static char	*ft_separate_line(char **line, char *holder_fd, int ret)
{
	int		i;
	char	*temp;

	i = 0;
	while (holder_fd[i] != '\n' && holder_fd[i] != '\0')
		i++;
	if (i < ft_strlen(holder_fd))
	{
		*line = ft_substr(holder_fd, 0, i);
		temp = ft_substr(holder_fd, i + 1, ft_strlen(holder_fd));
		free(holder_fd);
		holder_fd = ft_strdup(temp);
		free(temp);
	}
	else if (ret == 0)
	{
		*line = holder_fd;
		holder_fd = NULL;
	}
	return (holder_fd);
}

int	get_next_line(int fd, char **line, int ret)
{
	static char	*holder[MAX_FD];
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || fd >= MAX_FD || read(fd, holder[fd], 0) < 0)
		return (-1);
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		holder[fd] = ft_store_line(buff, holder[fd]);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret <= 0 && !holder[fd])
	{
		*line = ft_strdup("");
		return (ret);
	}
	holder[fd] = ft_separate_line(line, holder[fd], ret);
	if (ret <= 0 && !holder[fd])
		return (ret);
	return (1);
}
