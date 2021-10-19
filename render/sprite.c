/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:30:30 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/18 17:35:23 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fetch_p_location(t_us *us)
{
	int	x;
	int	y;

	y = 0;
	while (y < us->map.size_y)
	{
		x = 0;
		while (x < us->map.size_x)
		{
			if (us->map.tileset[y][x] == 'P')
			{
				us->player.x = x;
				us->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	render_sprite(t_us *us)
{
	if (us->player.x < 0 && us->player.y < 0)
		fetch_p_location(us);	
	mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->texture.p, us->player.x * A_W, us->player.y * A_H);
}
