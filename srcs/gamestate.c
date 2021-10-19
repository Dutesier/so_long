/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:49:47 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 13:04:41 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void max_coins(t_us *us)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < us->map.size_y)
	{
		x = 0;
		while (x < us->map.size_x)
		{
			if (us->map.tileset[y][x] == 'C')
				us->max_coins++;
			x++;
		}
		y++;
	}
}

int	gamestate(t_us *us)
{
	if (us->player.coins == us->max_coins)
	{
		us->gstate = 2;
		return (0);
	}
	else
		return (1);
}
