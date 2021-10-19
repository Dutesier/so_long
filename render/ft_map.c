/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:19:52 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 15:03:56 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_open_map(char *filename)
{
	int	fd;


	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0); // ERROR FUNCTION
	return (fd);
}

static int	fill_map(char *line, int y, t_us *us)
{
	int		x;

	if (y == 0)
		us->map.size_x = ft_strlen(line);
	us->map.tileset[y] = malloc((us->map.size_x + 1) * sizeof(char));
	if (us->map.tileset[y] == NULL)
		return (0); // NEEDS ERROR HANDLING
	x = 0;
	while (line[x] != '\0')
	{
		us->map.tileset[y][x] = line[x];
		x++;
	}
	us->map.tileset[y][x] = '\0';
	return (1);
}

// 
int	create_map(int fd, t_us *us)
{
	int		y;
	int		err;
	char	*line;

	err = 1;
	y = 0;
	line = NULL; // THIS might mess up gnl!
	us->map.tileset = malloc((us->map.size_y + 1) * sizeof(char *));
	if (us->map.tileset == NULL)
		return (0);//NEEDS ERROR HANDLING 
	while (y < us->map.size_y && err == 1)
	{
		get_next_line(fd, &line, 1);
		err = fill_map(line, y, us);
		y++;
	}
	if (err == 0)
		return (clean_map(us));
	us->map.tileset[y] = NULL;
	return (1);
}

void ft_map_to_img(t_us *us)
{
	int x;
	int y;

	y = 0;
	while (y < us->map.size_y)
	{
		x = 0;
		while (x < us->map.size_x)
		{
			mlx_put_image_to_window(us->vars.mlx, us->vars.win, ft_textu(us->map.tileset[y][x], us), (int)(x * A_W), (int)(y * A_H));
			x++;
		}
		y++;
	}
}

int map_init(t_us *us, char *filename)
{
	int fd;
	int err;

	us->map.size_y = map_to_line(filename);
	fd = ft_open_map(filename);
	err = create_map(fd, us);
	close(fd);
	if (map_len(us) || map_closed(us) || map_min(us, 0, 0, 0))
	{
		//delete map and return
		clean_map(us);
		return (1);
	}
	return (0);
}
