/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:57:09 by drtaili           #+#    #+#             */
/*   Updated: 2023/09/07 18:29:13 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

# define BLACK 0x000000
# define GRAY 0xAAAAAA
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define WHITE_SMOKE 0xf5f5f5

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x > WIN_WIDTH || y > WIN_HEIGHT || x <= 0 || y <= 0)
		return ;
    data->addr[y * WIN_WIDTH + x] = color;
}

void	draw_tile(int x, int y, int type, t_data *data)
{
	int	index_x;
	int	index_y;
	int	color;

	index_x = x - 1;
	index_y = y;
	while (index_y < (y + 10))
	{
		if (++index_x < (x + 10))
		{
			if (type == 1)
				color = BLACK;
			else if (type == 0)
				color = GRAY;
		    my_mlx_pixel_put(data, index_x, index_y, color);
        }
		else
		{
			index_x = x - 1;
			index_y++;
		}
	}
}

int	raycast_draw(double rot, double dist, int side, t_data *param)
{
	int		i;
	t_data	*data;

	data = param;
	int y_index = (data->pos.y * 10);
	int x_index = (data->pos.x * 10);
	i = 0;
	while (i++ < dist)
	{
		my_mlx_pixel_put(data, y_index, x_index, BLACK);
		x_index += side * cos(rot * M_PI / 180);
		y_index += side * -sin(rot * M_PI / 180);
	}
	return (1);
}

void	draw_fov(t_data *data)
{
	double	rotation_angle;
	double	begin_X;
	double	begin_Y;
    double		i;

	i = 0;
	rotation_angle = data->minimap.rot + 30;
	while (rotation_angle >= data->minimap.rot - 30)
	{	
		begin_X = data->pos.x * 10;
		begin_Y = data->pos.y * 10;
		i = 0;
    	while (i < 11)
    	{
        	begin_X += cos(rotation_angle * M_PI / 180);
        	begin_Y += sin(rotation_angle * M_PI / 180);
        	my_mlx_pixel_put(data, begin_Y, begin_X, 0xD1D0D0);
        	i++;
    	}
		rotation_angle = rotation_angle - 0.25;
	}
}
void	draw_player(t_data *data)
{
	double	rotation_angle;
	double	begin_X;
	double	begin_Y;
    int		i;

	i = 0;
	rotation_angle = data->minimap.rot + 30 + 180;
	while (rotation_angle >= data->minimap.rot - 30 + 180)
	{	
		begin_X = data->pos.x * 10;
		begin_Y = data->pos.y * 10;
		i = 0;
    	while (i < 5)
    	{
        	begin_X += cos(rotation_angle * M_PI / 180);
        	begin_Y += sin(rotation_angle * M_PI / 180);
        	my_mlx_pixel_put(data, begin_Y, begin_X, RED);
        	i++;
    	}
		rotation_angle = rotation_angle - 0.25;
	}
}

void	draw_map2d(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		if (++x < MAP_WIDTH)
		{
			if (data->map[y][x] == 1)
				draw_tile(x * 10, y * 10, 1, data);
			else if (data->map[y][x] == 0)
				draw_tile(x * 10, y * 10, 0, data);
		}
		else
		{
			x = -1;
			y++;
		}
	}
	draw_player(data);
	draw_fov(data);
}


//////////////////////////////////////////

static void	draw_line(t_data *data, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		data->addr[y * WIN_WIDTH + x] = 0xE11E00;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		data->addr[y * WIN_WIDTH + x] = 0xDC6400;
		y++;
	}
}
// floor : 0xDC6400 ceilling : 0xE11E00

static int	get_color(t_data *data, t_dda *dda_, t_raycast *rc)
{
	int	color;

	color = 0;
	//side = 0 => (top or bottom) 
	//side = 1 => (left or right)
	if (dda_->side == 0 && rc->ray.x > 0)//south
		color = *(data->cnv_addr1 + (data->tex_h * data->texy + data->texx));
	else if (dda_->side == 0 && rc->ray.x < 0)//north
		color = *(data->cnv_addr2 + (data->tex_h * data->texy + data->texx));
	else if (dda_->side == 1 && rc->ray.y > 0)//east
		color = *(data->cnv_addr3 + (data->tex_h * data->texy + data->texx));
	else if (dda_->side == 1 && rc->ray.y < 0)//west
		color = *(data->cnv_addr4 + (data->tex_h * data->texy + data->texx));
	return (color);
}

void	texture_prep(t_data *data, t_dda *dda_, t_raycast *rc)
{
	double	wallx;

	if (dda_->side == 0)
		wallx = data->pos.y + dda_->perp_wall_dist * rc->ray.y;
	else
		wallx = data->pos.x + dda_->perp_wall_dist * rc->ray.x;
	wallx -= floor(wallx);
	data->texx = (int)(wallx * (double)data->tex_w);
	if (dda_->side == 0 && rc->ray.x > 0) // (south)
		data->texx = data->tex_w - data->texx - 1;
	if (dda_->side == 1 && rc->ray.y < 0) // (west)
		data->texx = data->tex_w - data->texx - 1;
}

void	texture_loop(t_data *data, t_dda *dda_, t_raycast *rc, int x)
{
	double	step;
	double	texpos;
	int		y;
	int		color;

	color = 0;
	texture_prep(data, dda_, rc);
	step = 1.0 * data->tex_h / dda_->line_height;
	texpos = (dda_->draw_start - WIN_HEIGHT / 2 + dda_->line_height / 2) * step;
	y = dda_->draw_start;
	while (y < dda_->draw_end + 1)
	{
		data->texy = (int)texpos & (data->tex_h - 1);
		texpos += step;
		color = get_color(data, dda_, rc);
		if (dda_->side == 1)
			color = (color >> 1) & 8355711;
		data->addr[y * WIN_WIDTH + x] = color;
		y++;
	}
}

int	raycast(void *param)
{
	t_raycast	rc;
	t_dda		dda_;
	int			x;
	t_data		*data;

	x = 0;
	data = (t_data *)param;
	move_shape(data);
	while (x < WIN_WIDTH)
	{
		rc.camera_x = 2.0 * x / (double)WIN_WIDTH - 1;
		rc.ray.x = data->dir.x + data->plane.x * rc.camera_x;
		rc.ray.y = data->dir.y + data->plane.y * rc.camera_x;
		dda(data, &rc, &dda_);
		dda_.line_height = (int)(WIN_HEIGHT / dda_.perp_wall_dist);
		dda_.draw_start = (int)(-dda_.line_height / 2.0)
			+ (int)(WIN_HEIGHT / 2.0);
		if (dda_.draw_start < 0)
			dda_.draw_start = 0;
		dda_.draw_end = (int)(dda_.line_height / 2.0) + (int)(WIN_HEIGHT / 2.0);
		if (dda_.draw_end >= WIN_HEIGHT)
			dda_.draw_end = WIN_HEIGHT - 1;
		draw_line(data, x, dda_.draw_start);
		texture_loop(data, &dda_, &rc, x);
		x++;
	}
	draw_map2d(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr,
		data->mlx.win_ptr, data->img, 0, 0);
	return (0);
}
