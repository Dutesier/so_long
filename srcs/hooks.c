/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:32:12 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 13:14:34 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_movement(int keycode, t_us *us)
{
	store_move(keycode, us);
	if (move(us))
		return (1);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_vars	*dump;

	dump = vars;
	printf("Pressed %i\n", keycode);
	return (keycode);
}

int	ft_close(int keycode, t_vars *vars)
{
	t_vars	*dump;

	dump = vars;
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (keycode);
}

int	hello(int keycode, t_vars *vars)
{
	t_vars	*dump;

	dump = vars;
	printf("Hello\n");
	return (keycode);
}

int changecolor(int keycode, t_us *us)
{
	mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->nxt.img, 0, 0);
	keycode = 0;
	printf("Hello\n");
	return (1);
}
