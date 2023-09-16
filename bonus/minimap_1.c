/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:18:12 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/15 16:33:45 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_fov(t_data *data)
{
	double	rotation_angle;
	double	begin_x;
	double	begin_y;
	double	i;

	i = 0;
	rotation_angle = data->minimap.rot + 30;
	while (rotation_angle >= data->minimap.rot - 30)
	{
		begin_x = 100;
		begin_y = 100;
		i = 0;
		while (i < 11)
		{
			begin_x += cos(rotation_angle * M_PI / 180);
			begin_y += sin(rotation_angle * M_PI / 180);
			my_mlx_pixel_put(data, begin_y, begin_x, 0xD1D0D0);
			i++;
		}
		rotation_angle = rotation_angle - 0.25;
	}
}

void	draw_player(t_data *data)
{
	double	rotation_angle;
	double	begin_x;
	double	begin_y;
	int		i;

	i = 0;
	rotation_angle = data->minimap.rot + 30 + 180;
	while (rotation_angle >= data->minimap.rot - 30 + 180)
	{
		begin_x = 100;
		begin_y = 100;
		i = 0;
		while (i < 2)
		{
			begin_x += cos(rotation_angle * M_PI / 180);
			begin_y += sin(rotation_angle * M_PI / 180);
			my_mlx_pixel_put(data, begin_y, begin_x, RED);
			i++;
		}
		rotation_angle = rotation_angle - 0.25;
	}
}
