/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:55:29 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/10 17:58:09 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
			else if (type == -1)
				color = GRASS;
			my_mlx_pixel_put(data, index_x, index_y, color);
		}
		else
		{
			index_x = x - 1;
			index_y++;
		}
	}
}

void	draw_map2d_1(t_data *data, int x_player, int y_player)
{
	if (y_player >= 0 && y_player < (int)data->minimap.map_height
		&& x_player >= 0 && x_player < (int)data->minimap.map_width)
	{
		if (data->map_test[y_player][x_player] == 0)
			draw_tile(data->minimap.x * data->minimap.minimap_tile, \
				data->minimap.y * data->minimap.minimap_tile, 0, data);
		else if (data->map_test[y_player][x_player] == 1)
			draw_tile(data->minimap.x * data->minimap.minimap_tile, \
				data->minimap.y * data->minimap.minimap_tile, 1, data);
		else
			draw_tile(data->minimap.x * data->minimap.minimap_tile, \
				data->minimap.y * data->minimap.minimap_tile, -1, data);
	}
	else
		draw_tile(data->minimap.x * data->minimap.minimap_tile, \
				data->minimap.y * data->minimap.minimap_tile, -1, data);
}

void	draw_map2d(t_data *data)
{
	int			x_player;
	int			y_player;

	data->minimap.y = 0;
	y_player = data->pos.x - 10;
	while (data->minimap.y < 20)
	{
		data->minimap.x = 0;
		x_player = data->pos.y - 10;
		while (data->minimap.x < 20)
		{
			draw_map2d_1(data, x_player, y_player);
			data->minimap.x++;
			x_player++;
		}
		data->minimap.y++;
		y_player++;
	}
	draw_player(data);
	draw_fov(data);
}

// void	draw_map2d(t_data *data)
// {
// 	unsigned int	x;
// 	unsigned int	y;

// 	x = -1;
// 	y = 0;
// 	while (y < data->minimap.map_height)
// 	{
// 		if (++x < data->minimap.map_width)
// 		{
// 			if (data->map_test[y][x] == 1)
// 				draw_tile(x * data->minimap.minimap_tile, \
// 					y * data->minimap.minimap_tile, 1, data);
// 			else if (data->map_test[y][x] == 0)
// 				draw_tile(x * data->minimap.minimap_tile, \
// 					y * data->minimap.minimap_tile, 0, data);
// 		}
// 		else
// 		{
// 			x = -1;
// 			y++;
// 		}
// 	}
// 	draw_player(data);
// 	draw_fov(data);
// }
