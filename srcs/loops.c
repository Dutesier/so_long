/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:51:07 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/15 12:48:00 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame(t_us *us)
{
	if (us->res.curr_img == 1)
	{
		mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->nxt.img, 0, 0);
		sleep(2);
		us->res.curr_img = 2;
	}
	else
	{
		mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->data.img, 0, 0);
		sleep(2);
		us->res.curr_img = 1;
	}
	return (1);
}
