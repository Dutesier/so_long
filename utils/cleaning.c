/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:39:06 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 16:29:17 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void end_game(t_us *us)
{
	clean_map(us);
	mlx_destroy_image(us->vars.mlx, us->texture.a);
	mlx_destroy_image(us->vars.mlx, us->texture.b);
	mlx_destroy_image(us->vars.mlx, us->texture.c);
	mlx_destroy_image(us->vars.mlx, us->texture.e);
	mlx_destroy_image(us->vars.mlx, us->texture.p);
	mlx_destroy_image(us->vars.mlx, us->texture.p_alt);
	mlx_destroy_window(us->vars.mlx, us->vars.win);
	exit(0);
}

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
