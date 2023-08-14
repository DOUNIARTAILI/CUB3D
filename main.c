/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:50:06 by drtaili           #+#    #+#             */
/*   Updated: 2023/08/14 01:27:24 by drtaili          ###   ########.fr       */
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

void    Move_back_and_forth(t_data *data, int keycode)
{
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
}
void    move_sideways(t_data *data, int keycode)
{
    if (keycode == 2)//right
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
}

static int	close_win(t_data *data)
{
	(void)data;
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53 && data)
		exit(0);
    move_shape(data, keycode);
	return (0);
}
int mouse_move(int x, int y, t_data *data)
{
    (void)y;
    int old_x;
    if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGHT || y < 0)
        return (0);
    old_x = data->store_x;
    if (x < old_x)
        key_press(123, data);
    else if (x > old_x)
        key_press(124, data);
    data->store_x = x;
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
    mlx_hook(data.mlx.win_ptr, 6, 0, mouse_move, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
