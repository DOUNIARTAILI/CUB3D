/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:40:04 by drtaili           #+#    #+#             */
/*   Updated: 2023/08/14 05:11:10 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	rot_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dir.x;
	data->dir.x = data->dir.x * cos(-ROTSPEED)
		- data->dir.y * sin(-ROTSPEED);
	data->dir.y = olddirx * sin(-ROTSPEED) + data->dir.y * cos(-ROTSPEED);
	oldplanex = data->plane.x;
	data->plane.x = data->plane.x * cos(-ROTSPEED)
		- data->plane.y * sin(-ROTSPEED);
	data->plane.y = oldplanex * sin(-ROTSPEED)
		+ data->plane.y * cos(-ROTSPEED);
}

void	rot_left_right(t_data *data, int keycode)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 124)
		rot_right(data);
	else if (keycode == 123)
	{
		olddirx = data->dir.x;
		data->dir.x = data->dir.x * cos(ROTSPEED) - data->dir.y * sin(ROTSPEED);
		data->dir.y = olddirx * sin(ROTSPEED) + data->dir.y * cos(ROTSPEED);
		oldplanex = data->plane.x;
		data->plane.x = data->plane.x * cos(ROTSPEED)
			- data->plane.y * sin(ROTSPEED);
		data->plane.y = oldplanex * sin(ROTSPEED)
			+ data->plane.y * cos(ROTSPEED);
	}
}

void	move_shape(t_data *data, int keycode)
{
	if (keycode == 13 || keycode == 1)
		move_back_and_forth(data, keycode);
	else if (keycode == 2 || keycode == 0)
		move_sideways(data, keycode);
	else if (keycode == 123 || keycode == 124)
		rot_left_right(data, keycode);
	raycast(data);
}
