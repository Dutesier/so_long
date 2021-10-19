/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:03:21 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/15 11:47:02 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_offset(t_data *img, int x, int y, char *loc)
{
	//printf("---------|entered offset\n");
	loc = (img->addr) + (y * img->line_length + (x * img->bits_per_pixel / 8));
	//printf("---------|left offset: location %p\n", loc);
	return (loc);
}

void	pxl_to_img(t_data *img, int x, int y, int color)
{
	char *location;

	//printf("----Entered pixel to img\n");
	location = 0;
	location = ft_offset(img, x, y, location);
	*(unsigned int *)location = color;
}

void	whole_img(t_data *img, int color, int x, int y)
{
	int	i;
	int j;

	i = 0;
	//printf("heyho\n");
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			//printf("Changing at x: %i y: %i\n", j, i);
			pxl_to_img(img, j, i, color);
			j++;
		}
		i++;
	}
}
