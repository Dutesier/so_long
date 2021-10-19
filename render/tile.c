/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:34:36 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 15:04:40 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_us *us, char nickname, int x, int y)
{
	if (nickname == '0' || nickname == 'P')
		mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->texture.a, x * A_W, y * A_H);
	else if (nickname == 'C')
	{
		mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->texture.a, x * A_W, y * A_H);
		mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->texture.c, x * A_W, y * A_H);
	}
	else if (nickname == 'E')
	{
		mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->texture.a, x * A_W, y * A_H);
		mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->texture.e, x * A_W, y * A_H);
	}
	else
		mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->texture.b, x * A_W, y * A_H);

}

void	ft_consumables(t_us *us)
{
	int x;
	int y;

	y = 0;
	while (y < us->map.size_y)
	{
		x = 0;
		while (x < us->map.size_x)
		{
			if (us->map.tileset[y][x] == 'C')
				render_tile(us, 'C', x, y);
			if (us->map.tileset[y][x] == 'E')
				render_tile(us, 'E', x, y);
			x++;
		}
		y++;
	}
}
