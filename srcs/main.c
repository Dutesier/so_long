/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:09:20 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 16:19:38 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void so_long_init(t_us *us)
{
	us->gstate = 1;
	us->moves = 0;
	us->player.coins = 0;
	us->max_coins = 0;
	max_coins(us);
}

int main(int argc, char *argv[])
{
	t_us	us;	

	if (argc != 2)
		return (0);
	if (map_init(&us, argv[1]))
		return (1);
	//us.res.size_x = 100 * us.map.size_x;
	//us.res.size_y = 100 * us.map.size_y;
	so_long_init(&us);
	startWindow(&us);
	// Testing Screen Size
	/*int sizex;
	int sizey;
	mlx_get_screen_size(us.vars.mlx, &sizex, &sizey);
	printf("SIZE TEST: %i by %i\n", sizex, sizey);*/

	//us.data.img = mlx_new_image(us.vars.mlx, us.res.size_x, us.res.size_y);
	//us.data.addr = mlx_get_data_addr(us.data.img, &us.data.bits_per_pixel, &us.data.line_length, &us.data.endian);
	
	//us.nxt.img = mlx_new_image(us.vars.mlx, us.res.size_x, us.res.size_y);
	//us.nxt.addr = mlx_get_data_addr(us.nxt.img, &us.nxt.bits_per_pixel, &us.nxt.line_length, &us.nxt.endian);
	
	//whole_img(&us.data, 0x000000FF, 10, 10);
	//pxl_to_img(&us.data, 1, 1, 0x00F29EAB);
	//whole_img(&us.nxt, 0x0000FF00, 640, 480);
	//us.res.curr_img = 1;
	//mlx_put_image_to_window(us.vars.mlx, us.vars.win, us.data.img, 0, 0);
	
	//printf("us->data.img: %p\n", us.data.img);
	//whole_img(&us.data, 0x00FF0000, 640, 480);
	//whole_img(&us.nxt, 0x0000FF00, 640, 480);
	
	//mlx_key_hook(us.vars.win, changecolor, &us);

	
	
	ft_map_to_img(&us);
	ft_consumables(&us);	
	fetch_p_location(&us);
	us.player.next_x = us.player.x;
	us.player.next_y = us.player.y;

	render_sprite(&us);
	mlx_key_hook(us.vars.win, key_movement, &us);
	mlx_loop_hook(us.vars.mlx, gamestate, &us);
	//ft_load_bg(&us);

	mlx_loop(us.vars.mlx);
}
