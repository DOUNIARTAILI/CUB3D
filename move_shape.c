/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:40:04 by drtaili           #+#    #+#             */
/*   Updated: 2023/07/30 23:47:39 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    rot_left_right(t_data *data, int keycode)
{
    if (keycode == 124)//rot right
    {
        double oldDirX = data->dir.x;
        data->dir.x = data->dir.x * cos(-rotSpeed) - data->dir.y * sin(-rotSpeed);
        data->dir.y = oldDirX * sin(-rotSpeed) + data->dir.y * cos(-rotSpeed);
        double oldPlaneX = data->plane.x;
        data->plane.x = data->plane.x * cos(-rotSpeed) - data->plane.y * sin(-rotSpeed);
        data->plane.y = oldPlaneX * sin(-rotSpeed) + data->plane.y * cos(-rotSpeed);
    }
    else if (keycode == 123)//rot left
    {
        double oldDirX = data->dir.x;
        data->dir.x = data->dir.x * cos(rotSpeed) - data->dir.y * sin(rotSpeed);
        data->dir.y = oldDirX * sin(rotSpeed) + data->dir.y * cos(rotSpeed);
        double oldPlaneX = data->plane.x;
        data->plane.x = data->plane.x * cos(rotSpeed) - data->plane.y * sin(rotSpeed);
        data->plane.y = oldPlaneX * sin(rotSpeed) + data->plane.y * cos(rotSpeed);
    }
}

void    move_shape(t_data *data, int keycode)
{
    if (keycode == 13 || keycode == 1)
        Move_back_and_forth(data, keycode);
    else if (keycode == 2 || keycode == 0)
        move_sideways(data, keycode);
    else if (keycode == 123 || keycode == 124)
        rot_left_right(data, keycode);
    raycast(data);
}