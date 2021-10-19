/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:39:06 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/18 13:55:28 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_map(t_us *us)
{
	int y;

	y = 0;
	while (us->map.tileset[y] != NULL)
	{
		free(us->map.tileset[y]);
		y++;
	}
	free(us->map.tileset);
	return (0);
}
