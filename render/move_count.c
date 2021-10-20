/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:19:49 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/20 15:44:24 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_moves(t_us *us)
{
	char	*moves;

	moves = ft_itoa(us->moves);
	r_tile(us, '1', 0, 0);
	mlx_string_put(us->vars.mlx, us->vars.win, A_W * 0.1, 15, 1, "Moves:");
	mlx_string_put(us->vars.mlx, us->vars.win, A_W * 0.75, 15, 1, moves);
	free(moves);
}
