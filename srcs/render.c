/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:30:26 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/18 17:57:07 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	startWindow(t_us *us)
{
	us->vars.mlx = mlx_init();
	ft_init_textures(us);
	//us->res.size_x = us->texture.img_width * us->map.size_x;
	//us->res.size_y = us->texture.img_height * us->map.size_y;
	us->res.size_x = A_W * us->map.size_x;
	us->res.size_y = A_H * us->map.size_y;
	mlx_get_screen_size(us->vars.mlx, &us->res.max_x, &us->res.max_y);
	if (us->res.size_x > us->res.max_x || us->res.size_y > us->res.max_y)
		return ;// INSERT error msg about screen
	printf("Size x: %i, y: %i\nTexture w: %i, h: %i\n", us->res.size_x, us->res.size_y, us->texture.img_width, us->texture.img_height);
	us->vars.win = mlx_new_window(us->vars.mlx, us->res.size_x, us->res.size_y, "so_long");
}
