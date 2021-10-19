/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:00:21 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/18 18:02:27 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_to_line(char *filename) // Need to open and close file to reset read location
{
	int		ret;
	int		nl;
	char	buff;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
			return (-1);
	ret = 1;
	nl = -1;
	while (ret > 0)
	{
		ret = read(fd, &buff, sizeof(char));
		if (buff == '\n')
			nl++;
	}
	close(fd);
	if (ret < 0)
		return (-1); // or some error msg
	printf("Exiting map_to_line with nl: %i & buff: %c\n", nl, buff);
	return (nl);
}

int	map_len(t_us *us)
{
	printf("Map lens\n");
	int len;
	int y;

	y = 0;
	len = us->map.size_x;
	while (us->map.tileset[y] != NULL)
	{
		printf("map len y: %i\n", y);
		if (ft_strlen(us->map.tileset[y]) != len)
			return (1);
		y++;
	}
	return (0);
}

int map_closed(t_us *us)
{
	printf("Map clos\n");
	int x;
	int y;

	y = 0;
	while (y < us->map.size_y)
	{
		x = 0;
		while (x < us->map.size_x)
		{
			if ((y == 0 || y == us->map.size_y - 1) && us->map.tileset[y][x] != '1')
				return (1);
			if ((x == 0 || x == us->map.size_x - 1) && us->map.tileset[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int map_min(t_us *us, int p, int e, int c)
{
	printf("Map min\n");
	int x;
	int y;

	y = 0;
	while (y < us->map.size_y)
	{
		x = 0;
		while (x < us->map.size_x)
		{
			if (us->map.tileset[y][x] == 'P')
				p++;
			if (us->map.tileset[y][x] == 'E')
				e++;
			if (us->map.tileset[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (p != 1 || e < 1 || c < 1)
		return (1);
	return (0);
}
