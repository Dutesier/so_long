/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:54:15 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 16:35:27 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_tex(char *nickname)
{
	if (ft_strcmp(nickname, "bg"))
		return ("./assets/background.png");
	if (ft_strcmp(nickname, "0"))
		return ("./assets/a2.png");
	if (ft_strcmp(nickname, "1"))
		return ("./assets/b.png");
	if (ft_strcmp(nickname, "P"))
		return ("./assets/p.png");
	if (ft_strcmp(nickname, "A"))
		return ("./assets/p_alt.png");
	if (ft_strcmp(nickname, "C"))
		return ("./assets/c.png");
	if (ft_strcmp(nickname, "E"))
		return ("./assets/e.png");
	else
		return (0);
}

void	ft_init_texs(t_us *us)
{
	us->tex.a = mlx_png_file_to_image(us->vars.mlx,
			ft_tex("0"), &us->tex.img_width, &us->tex.img_height);
	us->tex.b = mlx_png_file_to_image(us->vars.mlx,
			ft_tex("1"), &us->tex.img_width, &us->tex.img_height);
	us->tex.p = mlx_png_file_to_image(us->vars.mlx,
			ft_tex("P"), &us->tex.img_width, &us->tex.img_height);
	us->tex.p_alt = mlx_png_file_to_image(us->vars.mlx,
			ft_tex("A"), &us->tex.img_width, &us->tex.img_height);
	us->tex.c = mlx_png_file_to_image(us->vars.mlx,
			ft_tex("C"), &us->tex.img_width, &us->tex.img_height);
	us->tex.e = mlx_png_file_to_image(us->vars.mlx,
			ft_tex("E"), &us->tex.img_width, &us->tex.img_height);
}

void	*ft_textu(char tile, t_us *us)
{
	if (tile == '1')
		return (us->tex.b);
	else
		return (us->tex.a);
}
