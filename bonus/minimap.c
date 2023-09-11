/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:55:29 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/11 20:01:08 by mmaqbour         ###   ########.fr       */
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
				color = D_BLUE;
			my_mlx_pixel_put(data, index_x, index_y, color);
		}
		else
		{
			index_x = x - 1;
			index_y++;
		}
	}
}

int	draw_map2d_1_1(t_data *data)
{
	if (sqrt((data->minimap.j_circle - 100) * (data->minimap.j_circle - 100) \
		+ (data->minimap.i_circle - 100) * (data->minimap.i_circle - 100)) \
		<= data->minimap.radius)
		return (1);
	return (0);
}

void	draw_map2d_1(t_data *data, int *i, int *j)
{
	if (((*j) / 32) >= 0 && ((*j) / 32) < (int)data->minimap.map_height \
			&& ((*i) / 32) >= 0 && ((*i) / 32) < (int)data->minimap.map_width)
	{
		if (data->map_test[((*j) / 32)][((*i) / 32)] == 0
			&& draw_map2d_1_1(data))
			my_mlx_pixel_put(data, data->minimap.x_save \
				, data->minimap.y_save, GRAY);
		else if (data->map_test[((*j) / 32)][((*i) / 32)] == 1
			&& draw_map2d_1_1(data))
			my_mlx_pixel_put(data, data->minimap.x_save \
				, data->minimap.y_save, BLACK);
		else if (draw_map2d_1_1(data))
			my_mlx_pixel_put(data, data->minimap.x_save \
				, data->minimap.y_save, D_BLUE);
	}
	else if (draw_map2d_1_1(data))
		my_mlx_pixel_put(data, data->minimap.x_save \
			, data->minimap.y_save, D_BLUE);
	(*i)++;
	data->minimap.x_save++;
	data->minimap.i_circle++;
}

void	draw_map2d(t_data *data)
{
	int	y;
	int	x;
	int	j;
	int	i;

	x = data->pos.y * 32;
	data->minimap.j_circle = 0;
	y = data->pos.x * 32;
	i = x - 100;
	j = y - 100;
	data->minimap.y_save = 0;
	while (j < y + 100)
	{
		i = x - 100;
		data->minimap.i_circle = 0;
		data->minimap.x_save = 0;
		while (i < x + 100)
			draw_map2d_1(data, &i, &j);
		j++;
		data->minimap.j_circle++;
		data->minimap.y_save++;
	}
	draw_player(data);
	draw_fov(data);
}
