/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:57:09 by drtaili           #+#    #+#             */
/*   Updated: 2023/07/29 23:26:20 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	draw_line(t_data *data, int x, int draw_start, int draw_end, int color)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
        data->addr[y * WIN_WIDTH + x] = 0x87CEEB;
		y++;
	}
	while (y < draw_end)
	{
        data->addr[y * WIN_WIDTH + x] = color;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
        data->addr[y * WIN_WIDTH + x] = 0x009A17;
		y++;
	} 
}

static int	get_color(int wall_id)
{
	if (wall_id == 1)
		return (0x0000FF);
	else if (wall_id == 2)
		return (0x00FF00);
	else if (wall_id == 3)
		return (0xFF0000);
	else if (wall_id == 4)
		return (0xFFFF00);
	else
		return (0);
}

void	raycast(t_data *data)
{
    t_raycast	rc;
	t_dda		dda_;
    int         color;
    int         x;

    x = 0;
	while (x < WIN_WIDTH)
	{
        rc.camera_x = 2.0 * x / (double)WIN_WIDTH - 1;
		rc.ray.x = data->dir.x + data->plane.x * rc.camera_x;
		rc.ray.y = data->dir.y + data->plane.y * rc.camera_x;
		dda(data, &rc, &dda_);
		dda_.line_height = (int)(WIN_HEIGHT / dda_.perp_wall_dist);
        dda_.draw_start = (int)(-dda_.line_height / 2.0) + (int)(WIN_HEIGHT / 2.0);
	    if (dda_.draw_start < 0)
		    dda_.draw_start = 0;
	    dda_.draw_end = (int)(dda_.line_height / 2.0) + (int)(WIN_HEIGHT / 2.0);
	    if (dda_.draw_end >= WIN_HEIGHT)
		    dda_.draw_end = WIN_HEIGHT - 1;
		color = get_color(data->map[(int)dda_.map_x][(int)dda_.map_y]);
		if (dda_.side == Y)
			color /= 2;
		draw_line(data, x, dda_.draw_start, dda_.draw_end, color);
        x++;
	}
    mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img, 0, 0);
}