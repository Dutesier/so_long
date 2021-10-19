/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:54:15 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 13:20:06 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_texture(char *nickname)
{
	if (ft_strcmp(nickname, "bg"))
		return ("./assets/background.png");
	if (ft_strcmp(nickname, "0"))
		return ("./assets/a2.png");
	if (ft_strcmp(nickname, "1"))
		return ("./assets/b.png");
	if (ft_strcmp(nickname, "P"))
		return ("./assets/p.png");
	if (ft_strcmp(nickname, "C"))
		return ("./assets/c.png");
	if (ft_strcmp(nickname, "E"))
		return ("./assets/e.png");
	else
		return (0);
}

void	ft_init_textures(t_us *us)
{
	us->texture.a = mlx_png_file_to_image(us->vars.mlx, ft_texture("0"), &us->texture.img_width, &us->texture.img_height);
	us->texture.b = mlx_png_file_to_image(us->vars.mlx, ft_texture("1"), &us->texture.img_width, &us->texture.img_height);
	us->texture.p = mlx_png_file_to_image(us->vars.mlx, ft_texture("P"), &us->texture.img_width, &us->texture.img_height);
	us->texture.c = mlx_png_file_to_image(us->vars.mlx, ft_texture("C"), &us->texture.img_width, &us->texture.img_height);
	us->texture.e = mlx_png_file_to_image(us->vars.mlx, ft_texture("E"), &us->texture.img_width, &us->texture.img_height);

}

void *ft_textu(char tile, t_us *us)
{
	printf("ft_textu\n");
	if (tile == '1')
		return (us->texture.b);
	else
		return (us->texture.a);
}

void ft_load_bg(t_us *us)
{
	us->texture.img = mlx_png_file_to_image(us->vars.mlx, ft_texture("bg"), &us->texture.img_width, &us->texture.img_height);
	mlx_put_image_to_window(us->vars.mlx, us->vars.win, us->texture.img, 0, 0);
	
}
