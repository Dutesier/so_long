/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:09:20 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/20 15:44:26 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	so_long_init(t_us *us)
{
	us->gstate = 1;
	us->moves = 0;
	us->p.coins = 0;
	us->max_coins = 0;
	max_coins(us);
}

int	main(int argc, char *argv[])
{
	t_us	us;	

	if (argc != 2)
		return (0);
	if (map_init(&us, argv[1]))
		return (1);
	so_long_init(&us);
	start__window(&us);
	ft_map_to_img(&us);
	ft_consumables(&us);
	fetch_p_location(&us);
	us.p.next_x = us.p.x;
	us.p.next_y = us.p.y;
	render_sprite(&us);
	mlx_string_put(us.vars.mlx, us.vars.win, A_W * 0.1, 15, 1, "Moves:  0");
	mlx_key_hook(us.vars.win, key_movement, &us);
	mlx_loop_hook(us.vars.mlx, gamestate, &us);
	mlx_loop(us.vars.mlx);
}
