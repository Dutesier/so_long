/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:14:53 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 13:22:46 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void store_move(int keycode, t_us *us)
{
	us->player.next_x = us->player.x;
	us->player.next_y = us->player.y;
	if (keycode == UP)
		us->player.next_y--;
	if (keycode == DOWN)
		us->player.next_y++;
	if (keycode == LEFT)
		us->player.next_x--;
	if (keycode == RIGHT)
		us->player.next_x++;
}

int	check_move(t_us *us)
{
	int x;
	int y;

	x = us->player.next_x;
	y = us->player.next_y;
	if (us->map.tileset[y][x] == '1')
		return (0);
	return (1);
}

static void	move_sprite(t_us *us)
{
	us->player.x = us->player.next_x;
	us->player.y = us->player.next_y;
	us->moves++;
	render_sprite(us);
	printf("Moves: %i\n", us->moves);
}

int	move(t_us *us) // MISSING EXIT
{
	if (check_move(us))
	{
		if (us->map.tileset[us->player.next_y][us->player.next_x] == 'C')
		{
			us->map.tileset[us->player.next_y][us->player.next_x] = '0';
			us->player.coins++;
		}
		if (us->map.tileset[us->player.next_y][us->player.next_x] == 'E')
		{
			if (us->gstate == 1)
			{
				render_tile(us, us->map.tileset[us->player.y][us->player.x], us->player.x, us->player.y);
				move_sprite(us);

				return (1);
			}
			else
				return (1);

		}
		printf("Player x & y : %i %i\nTileset: %c\n", us->player.x, us->player.y, us->map.tileset[us->player.y][us->player.x]);
		render_tile(us, us->map.tileset[us->player.y][us->player.x], us->player.x, us->player.y);
		move_sprite(us);
		return (1);
	}
	else
		return (0);
}