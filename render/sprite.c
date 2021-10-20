/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:30:30 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 17:02:38 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_direction(t_us *us)
{
	if (us->p.x > us->p.next_x)
		us->p.d = 'L';
	if (us->p.x < us->p.next_x)
		us->p.d = 'R';
}

void	fetch_p_location(t_us *us)
{
	int	x;
	int	y;

	y = 0;
	while (y < us->map.size_y)
	{
		x = 0;
		while (x < us->map.size_x)
		{
			if (us->map.tile[y][x] == 'P')
			{
				us->p.x = x;
				us->p.y = y;
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
	if (us->p.x < 0 && us->p.y < 0)
		fetch_p_location(us);
	if (us->p.d == 'L')
		mlx_put_image_to_window(us->vars.mlx, us->vars.win,
			us->tex.p_alt, us->p.x * A_W, us->p.y * A_H);
	else
		mlx_put_image_to_window(us->vars.mlx, us->vars.win,
			us->tex.p, us->p.x * A_W, us->p.y * A_H);
}
