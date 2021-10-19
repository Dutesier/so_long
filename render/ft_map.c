/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:19:52 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 12:27:49 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_open_map(char *filename)
{
	int	fd;

	printf("ft_open_map\n");

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0); // ERROR FUNCTION
	return (fd);
}

static int	fill_map(char *line, int y, t_us *us)
{
	int		x;

	printf("fill_map\n");
	printf("Line: %s\n", line);
	if (y == 0)
		us->map.size_x = ft_strlen(line);
	us->map.tileset[y] = malloc((us->map.size_x + 1) * sizeof(char));
	if (us->map.tileset[y] == NULL)
		return (0); // NEEDS ERROR HANDLING
	x = 0;
	while (line[x] != '\0')
	{
		printf("Filling us->map.tileset[%i][%i] with %c\n", y, x, line[x]);
		us->map.tileset[y][x] = line[x];
		x++;
	}
	us->map.tileset[y][x] = '\0';
	printf("left fill_map\n");
	return (1);
}

// 
int	create_map(int fd, t_us *us)
{
	int		y;
	int		err;
	char	*line;

	printf("create_map\n");
	err = 1;
	y = 0;
	line = NULL; // THIS might mess up gnl!
	us->map.tileset = malloc((us->map.size_y + 1) * sizeof(char *));
	if (us->map.tileset == NULL)
		return (0);//NEEDS ERROR HANDLING 
	while (y < us->map.size_y && err == 1)
	{
		get_next_line(fd, &line, 1);
		printf("Line from gnl: %s\n", line);
		err = fill_map(line, y, us);
		y++;
	}
	if (err == 0)
		return (clean_map(us));
	us->map.tileset[y] = NULL;
	printf("left create_map\n");
	return (1);
}

void ft_map_to_img(t_us *us)
{
	int x;
	int y;

	printf("map_to_image\n");
	printf("us->map.size_x: %i, size_y: %i\n", us->map.size_x, us->map.size_y);
	
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
	printf("Closed fd\n");
	if (map_len(us) || map_closed(us) || map_min(us, 0, 0, 0))
	{
		//delete map and return
		clean_map(us);
		printf("Left map_init due to map error\n");
		return (1);
	}
	printf("Left map_init\n");
	return (0);
}
