/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:55:57 by drtaili           #+#    #+#             */
/*   Updated: 2023/08/14 01:48:36 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     CUBE3D_H
#define CUBE3D_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
#include <string.h>
# include <unistd.h>

# define WIN_WIDTH  640
# define WIN_HEIGHT 480

# define X          0
# define Y          1

# define map_width  24
# define map_height 24

# define moveSpeed 0.9
# define rotSpeed 0.1


typedef struct  s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_mlx;

typedef struct
{
    double  x;
    double  y;
}   t_vec;

typedef struct
{
    t_mlx   mlx;
    void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    t_vec   pos;
    t_vec   dir;
    t_vec   plane;
    int     map[map_width][map_height];
    int     store_x;
    void    *cnv_img;
    void    *img_ptr;
    int     *cnv_addr;
    int     cnv_w;
    int     cnv_h;
    int		cnv_bpp;
	int		cnv_ll;
	int		cnv_en;
}   t_data;

typedef struct
{
    double  camera_x;
    t_vec   ray;
}   t_raycast;

typedef struct
{
    int     map_x;
    int     map_y;
    t_vec   side_dist;
    t_vec   delta_dist;
    double  perp_wall_dist;
    int     step_x;
    int     step_y;
    int     hit;
    int     side;
    int     line_height;
    int     draw_start;
    int     draw_end;
}   t_dda;

void	ft_init(t_data *data);
void	raycast(t_data *data);
void	ft_map(int dst[map_width][map_height], int src[map_width][map_height]);
void	dda(t_data *data, t_raycast *rc, t_dda *dda_);
void    rot_left_right(t_data *data, int keycode);
void    Move_back_and_forth(t_data *data, int keycode);
void    move_sideways(t_data *data, int keycode);
void    move_shape(t_data *data, int keycode);

#endif