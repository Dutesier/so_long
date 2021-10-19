/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:07:34 by dareias-          #+#    #+#             */
/*   Updated: 2021/10/19 17:43:21 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include <unistd.h> //Remove?

//Keys
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

//Assets
#define A_H 127
#define A_W 127

//Structs
typedef struct	s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian; 
}				t_data;

typedef struct	s_res {
	int size_x;
	int size_y;
	int curr_img;
	int	max_x;
	int max_y;
}				t_res;

typedef struct	s_extu{
	void	*img;
	void	*a;
	void	*b;
	void	*c;
	void	*e;
	void	*p;
	void	*p_alt;
	int		img_width;
	int		img_height;
}				t_extu;

typedef struct	s_map{
	char	**tileset;
	int		size_x;
	int		size_y;
}				t_map;

typedef struct	s_play{
	int		x;
	int		y;
	int		next_x;
	int		next_y;
	int		coins;
	int		d;
}				t_play;

typedef struct	s_us {
	t_vars	vars;
	t_data	data;
	t_data	nxt;
	t_res	res;
	t_extu	texture;
	t_map	map;
	t_play	player;
	int		gstate;
	int		moves;
	int		max_coins;
}				t_us;

//Initialization
void	startWindow(t_us *us);
void	ft_init_textures(t_us *us);
int		 map_init(t_us *us, char *filename);
void	fetch_p_location(t_us *us);

//Tests
void	pxl_to_img(t_data *img, int x, int y, int color);
void	whole_img(t_data *img, int color, int x, int y);
int		render_frame(t_us *us);

int		key_hook(int keycode, t_vars *vars);
int		hello(int keycode, t_vars *vars);
int		ft_close(int keycode, t_vars *vars);

int		changecolor(int keycode, t_us *us);
//Hooks
int key_movement(int keycode, t_us *us);
void store_move(int keycode, t_us *us);
int	check_move(t_us *us);
int	move(t_us *us);

//Rendering
int	create_map(int fd, t_us *us);
void *ft_textu(char tile, t_us *us);
void ft_map_to_img(t_us *us);
int	map_to_line(char *filename);
void	render_sprite(t_us *us);
void	render_tile(t_us *us, char nickname, int x, int y);
void	ft_consumables(t_us *us);
void	update_direction(t_us *us);

//Gamestate
void max_coins(t_us *us);
int gamestate(t_us *us);

//Error Checking
int	map_len(t_us *us);
int map_closed(t_us *us);
int map_min(t_us *us, int p, int e, int c);
int map_keys(t_us *us);
int	is_invalid_key(char k);
int		map_error(t_us *us);
void	map_error_msg(int error);

//Utils
int	ft_strcmp(char *one, char *two);

//Cleaning
int	clean_map(t_us *us);
void end_game(t_us *us);

#endif
