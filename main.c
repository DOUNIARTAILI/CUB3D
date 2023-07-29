/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:50:06 by drtaili           #+#    #+#             */
/*   Updated: 2023/07/29 23:34:22 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int map[map_width][map_height] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static int	close_win(t_data *data)
{
	(void)data;
	exit(0);
}

void move_shape(t_data *data, int keycode)
{
    // if ((keycode == 123 || keycode == 124 || keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13) && data)
    if (keycode == 13)//up
    {
        if (map[(int)(data->pos.x + data->dir.x * moveSpeed)][(int)data->pos.y] == 0)
            data->pos.x += data->dir.x * moveSpeed;
        if (map[(int)data->pos.x][(int)(data->pos.y + data->dir.y * moveSpeed)] == 0)
            data->pos.y += data->dir.y * moveSpeed;
    }
    else if (keycode == 1)//down
    {
        if (map[(int)(data->pos.x - data->dir.x * moveSpeed)][(int)data->pos.y] == 0)
            data->pos.x -= data->dir.x * moveSpeed;
        if (map[(int)data->pos.x][(int)(data->pos.y - data->dir.y * moveSpeed)] == 0)
            data->pos.y -= data->dir.y * moveSpeed;
    }
    else if (keycode == 2)//right
    {
        if (map[(int)(data->pos.x + data->plane.x * moveSpeed)][(int)data->pos.y] == 0)
            data->pos.x += data->plane.x * moveSpeed;
        if (map[(int)data->pos.x][(int)(data->pos.y + data->plane.y * moveSpeed)] == 0)
            data->pos.y += data->plane.y * moveSpeed;
    }
    else if (keycode == 0)//left
    {
        if (map[(int)(data->pos.x - data->plane.x * moveSpeed)][(int)data->pos.y] == 0)
            data->pos.x -= data->plane.x * moveSpeed;
        if (map[(int)data->pos.x][(int)(data->pos.y - data->plane.y * moveSpeed)] == 0)
            data->pos.y -= data->plane.y * moveSpeed;
    }
    else if (keycode == 124)//rot right
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
    raycast(data);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53 && data)
		exit(0);
    move_shape(data, keycode);
	return (0);
}

int	main()
{
	t_data	data;
    ft_map(data.map, map);
	ft_init(&data);
	raycast(&data);
    mlx_hook(data.mlx.win_ptr, 17, 0, close_win, &data);
    mlx_hook(data.mlx.win_ptr, 2, 0, key_press, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
