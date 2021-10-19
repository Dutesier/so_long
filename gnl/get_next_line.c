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
	if (i < ft_strlen(holder_fd)) // if it has a newline somewhen in the string (holder_fd)
	{
		*line = ft_substr(holder_fd, 0, i); // We store in line the substr of holder up to the newline char
		temp = ft_substr(holder_fd, i + 1, ft_strlen(holder_fd)); // and we store the remainder of holder_fd in new holder_fd
		free(holder_fd);
		holder_fd = ft_strdup(temp);
		free(temp);
	}
	else if (ret == 0) // already read till EOF
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
		ret = read(fd, buff, BUFFER_SIZE); // Read from the file into buff at BUFFER_SIZE chuncks
		if (ret < 0) // If it cannot be read
			return (-1);
		buff[ret] = '\0'; // Null terminate the buffer
		holder[fd] = ft_store_line(buff, holder[fd]); // Store in holder what I've read
		if (ft_strchr(buff, '\n')) // If i've already started reading into the next line -> break
			break ;
	}
	if (ret <= 0 && !holder[fd])
	{
		*line = ft_strdup("");
		return (ret);
	}
	holder[fd] = ft_separate_line(line, holder[fd], ret); // We store in char **line up to the \n char
	if (ret <= 0 && !holder[fd]) // if we've reached EOF
		return (ret);
	return (1);
}
