/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:55:57 by drtaili           #+#    #+#             */
/*   Updated: 2023/09/11 11:06:15 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WIN_WIDTH  1920
# define WIN_HEIGHT 1080

# define X          0
# define Y          1

# define MOVESPEED 0.08
# define ROTSPEED 0.05

# define BLACK 0x000000
# define GRAY 0xAAAAAA
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define D_BLUE 0x00008b
# define GRASS 0x7CFC00

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct minimap
{
	unsigned int	map_width;
	unsigned int	map_height;
	unsigned int	x;
	unsigned int	y;
	int				keycode;
	int				keycode_move;
	int				keycode_rotate;	
	int				keycode_sides;
	t_vec			pos_mini;
	double			rot;
	int				mouse_move;
	int				turn_direction;
	int				minimap_tile;
}	t_minimap;

typedef struct s_data
{
	t_minimap		minimap;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	t_mlx			mlx;
	t_vec			pos;
	t_vec			dir;
	t_vec			plane;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				**map_test;
	int				store_x;
	void			*cnv_img1;
	int				*cnv_addr1;
	int				tex_w;
	int				tex_h;
	int				tex_w1;
	int				tex_h1;
	int				tex_w2;
	int				tex_h2;
	int				tex_w3;
	int				tex_h3;
	int				tex_w4;
	int				tex_h4;
	int				cnv_bpp1;
	int				cnv_ll1;
	int				cnv_en1;
	void			*cnv_img2;
	int				*cnv_addr2;
	int				cnv_bpp2;
	int				cnv_ll2;
	int				cnv_en2;
	void			*cnv_img3;
	int				*cnv_addr3;
	int				cnv_bpp3;
	int				cnv_ll3;
	int				cnv_en3;
	void			*cnv_img4;
	int				*cnv_addr4;
	int				cnv_bpp4;
	int				cnv_ll4;
	int				cnv_en4;
	int				texx;
	int				texy;
}	t_data;

typedef struct s_raycast
{
	double	camera_x;
	t_vec	ray;
}	t_raycast;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	t_vec	side_dist;
	t_vec	delta_dist;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_dda;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_game
{
	unsigned int	map_lnght;
	unsigned int	map_hght;
	unsigned int	map_h_tmp;
	char			**map_components;
	unsigned int	ceil_color;
	unsigned int	floor_color;
	t_rgb			rgb;
	double			p_pos_x;
	double			p_pos_y;
}	t_game;

int		ft_init(t_data *data, t_game *game);
int		raycast(void *param);
void	dda(t_data *data, t_raycast *rc, t_dda *dda_);
void	rot_left_right(t_data *data, int keycode);
void	move_back_and_forth(t_data *data, int keycode);
void	move_sideways(t_data *data, int keycode);
void	move_back_and_forth(t_data *data, int keycode);
void	move_shape(t_data *data);
int		close_win(t_data *data);

int		my_return_mistake(int i);
void	parsing(const char *map, int fd, t_data *data, t_game *game);
int		pars_map(t_game *game, const char *map, int fd, t_data *data);
int		pars_textures1(char *line, t_data *data);
int		pars_textures2(t_game *game, t_data *data, char *line, char c);
void	draw_line(t_data *data, int x, int draw_start);
int		get_color(t_data *data, t_dda *dda_, t_raycast *rc);
int		my_check_map(t_game *game, t_data *data);
void	draw_map2d(t_data *data);
void	my_free_map_components(t_game *game);
int		my_free_map_components2(t_game *game);
int		free_map(t_data *data, unsigned int height);
char	*my_strchr(const char *s, int c);
void	draw_player(t_data *data);
void	draw_fov(t_data *data);
int		raycast_draw(double rot, double dist, int side, t_data *param);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		check_valid_lines(t_game *game);
int		check_if_player(t_game *game);
int		my_strlen(const char *s);
int		check_textures1(int sign, t_data *data);
void	get_textures_add(int sign, t_data *data);
int		check_textures2(int sign, t_data *data);
void	draw_tile(int x, int y, int type, t_data *data);
int		all_spaces(char *str);
int		check_line(char *line);
int		contain_one(char *line);

#endif