/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:20:02 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 17:43:24 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_keys(t_us *us)
{
	int x;
	int y;

	y = 0;
	while (y < us->map.size_y)
	{
		x = 0;
		while (x < us->map.size_x)
		{
			if (is_invalid_key(us->map.tileset[y][x]))
				return (1); // Some error msg
			x++;
		}
		y++;
	}
	return (0);
}

void	map_error_msg(int error)
{
	if (error == 1)
		printf("Different line sizes\n");
	if (error == 2)
		printf("Map not closed by walls\n");
	if (error == 3)
		printf("Wrong number of Players / Collectibles / Exits\n");
	if (error == 4)
		printf("Contains Invalid keys\n");
}

int map_error(t_us *us)
{
	if (map_len(us))
		return (1);
	if (map_closed(us))
		return (2);
	if (map_min(us, 0, 0, 0))
		return (3);
	if (map_keys(us))
		return (4);
	return (0);	
}
