/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:30:26 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/20 15:29:36 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start__window(t_us *us)
{
	us->vars.mlx = mlx_init();
	ft_init_texs(us);
	us->res.size_x = A_W * us->map.size_x;
	us->res.size_y = A_H * us->map.size_y;
	mlx_get_screen_size(us->vars.mlx, &us->res.max_x, &us->res.max_y);
	if (us->res.size_x > us->res.max_x || us->res.size_y > us->res.max_y)
		printf("Warning: Map too big to fit in screen\n");
	us->vars.win = mlx_new_window(us->vars.mlx, us->res.size_x,
			us->res.size_y, "so_long");
}
