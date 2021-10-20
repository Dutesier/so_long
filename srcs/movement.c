/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:14:53 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/20 15:27:12 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	resetxy(t_us *us)
{
	us->p.next_x = us->p.x;
	us->p.next_y = us->p.y;
	return (0);
}

void	store_move(int keycode, t_us *us)
{
	if (keycode == ESC)
		end_game(us);
	if (keycode == UP)
		us->p.next_y = us->p.y - 1;
	if (keycode == DOWN)
		us->p.next_y = us->p.y + 1;
	if (keycode == LEFT)
		us->p.next_x = us->p.x - 1;
	if (keycode == RIGHT)
		us->p.next_x = us->p.x + 1;
}

int	check_move(t_us *us)
{
	int	x;
	int	y;

	x = us->p.next_x;
	y = us->p.next_y;
	if (us->map.tile[y][x] == '1')
		return (resetxy(us));
	if (us->p.x == x)
	{
		if (us->p.y == y)
			return (resetxy(us));
	}
	return (1);
}

static void	move_sprite(t_us *us)
{
	update_direction(us);
	us->p.x = us->p.next_x;
	us->p.y = us->p.next_y;
	us->moves++;
	render_sprite(us);
	render_moves(us);
	printf("Moves: %i\n", us->moves);
}

int	move(t_us *us)
{
	if (check_move(us))
	{
		if (us->map.tile[us->p.next_y][us->p.next_x] == 'C')
		{
			us->map.tile[us->p.next_y][us->p.next_x] = '0';
			us->p.coins++;
		}
		if (us->map.tile[us->p.next_y][us->p.next_x] == 'E')
		{
			if (us->gstate == 1)
			{
				r_tile(us, us->map.tile[us->p.y][us->p.x], us->p.x, us->p.y);
				move_sprite(us);
				return (1);
			}
			else
				end_game(us);
		}
		r_tile(us, us->map.tile[us->p.y][us->p.x], us->p.x, us->p.y);
		move_sprite(us);
		return (1);
	}
	else
		return (0);
}
