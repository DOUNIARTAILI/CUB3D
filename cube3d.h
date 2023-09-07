/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:55:57 by drtaili           #+#    #+#             */
/*   Updated: 2023/09/07 17:01:20 by drtaili          ###   ########.fr       */
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

# define WIN_WIDTH  1200
# define WIN_HEIGHT 1200

# define X          0
# define Y          1

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# define MOVESPEED 0.9
# define ROTSPEED 0.06

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
	int		keycode;
	int		keycode_move;
	int		keycode_rotate;	
	int		keycode_sides;
	t_vec	pos_mini;
	double	rot;
	int		mouse_move;
	int		turn_direction;
} t_minimap;

typedef struct s_data
{
	t_mlx	mlx;
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map[MAP_WIDTH][MAP_HEIGHT];
	int		store_x;
	void	*cnv_img1;
	int		*cnv_addr1;
	int		tex_w;
	int		tex_h;
	int		cnv_bpp1;
	int		cnv_ll1;
	int		cnv_en1;
	void	*cnv_img2;
	int		*cnv_addr2;
	int		cnv_bpp2;
	int		cnv_ll2;
	int		cnv_en2;
	void	*cnv_img3;
	int		*cnv_addr3;
	int		cnv_bpp3;
	int		cnv_ll3;
	int		cnv_en3;
	void	*cnv_img4;
	int		*cnv_addr4;
	int		cnv_bpp4;
	int		cnv_ll4;
	int		cnv_en4;
	int		texx;
	int		texy;
	t_minimap	minimap;
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


void	ft_init(t_data *data);
int		raycast(void *param);
void	ft_map(int dst[MAP_WIDTH][MAP_HEIGHT], int src[MAP_WIDTH][MAP_HEIGHT]);
void	dda(t_data *data, t_raycast *rc, t_dda *dda_);
void	rot_left_right(t_data *data, int keycode);
void	move_back_and_forth(t_data *data, int keycode);
void	move_sideways(t_data *data, int keycode);
void	move_shape(t_data *data);
int		close_win(t_data *data);

#endif