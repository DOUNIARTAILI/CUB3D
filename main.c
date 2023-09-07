/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:50:06 by drtaili           #+#    #+#             */
/*   Updated: 2023/09/07 17:35:02 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int map[MAP_WIDTH][MAP_HEIGHT] =
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

void	move_back_and_forth(t_data *data, int keycode)
{
	if (keycode == 13)//up
	{
		if (map[(int)(data->pos.x + data->dir.x
				* MOVESPEED)][(int)data->pos.y] == 0)
			data->pos.x += data->dir.x * MOVESPEED;
		if (map[(int)data->pos.x][(int)(data->pos.y
			+ data->dir.y * MOVESPEED)] == 0)
			data->pos.y += data->dir.y * MOVESPEED;
	}
	else if (keycode == 1)//down
	{
		if (map[(int)(data->pos.x - data->dir.x
				* MOVESPEED)][(int)data->pos.y] == 0)
			data->pos.x -= data->dir.x * MOVESPEED;
		if (map[(int)data->pos.x][(int)(data->pos.y
			- data->dir.y * MOVESPEED)] == 0)
			data->pos.y -= data->dir.y * MOVESPEED;
	}
}

void	move_sideways(t_data *data, int keycode)
{
	if (keycode == 2)//right
	{
		if (map[(int)(data->pos.x + data->plane.x
				* MOVESPEED)][(int)data->pos.y] == 0)
			data->pos.x += data->plane.x * MOVESPEED;
		if (map[(int)data->pos.x][(int)(data->pos.y
			+ data->plane.y * MOVESPEED)] == 0)
			data->pos.y += data->plane.y * MOVESPEED;
	}
	else if (keycode == 0)//left
	{
		if (map[(int)(data->pos.x - data->plane.x
				* MOVESPEED)][(int)data->pos.y] == 0)
			data->pos.x -= data->plane.x * MOVESPEED;
		if (map[(int)data->pos.x][(int)(data->pos.y
			- data->plane.y * MOVESPEED)] == 0)
			data->pos.y -= data->plane.y * MOVESPEED;
	}
}

int	key_press(int keycode, t_data *data)
{
	// if (keycode == 53 && data)
	// 	exit(0);
	// move_shape(data, keycode);
	if (keycode == 53 && data)
		exit(0);
	if (keycode == 13 || keycode == 1)
		data->minimap.keycode_move = keycode;
	if (keycode == 2 || keycode == 0)
		data->minimap.keycode_sides = keycode;
	if (keycode == 124 || keycode == 123)
		data->minimap.keycode_rotate = keycode;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	// if (keycode == 53 && data)
	// 	exit(0);
	if (keycode == 124 || keycode == 123)
	{
		data->minimap.turn_direction = 0;
		data->minimap.keycode_rotate = -1;
	}
	if (keycode == 13 || keycode == 1)
		data->minimap.keycode_move = -1;
	if (keycode == 2 || keycode == 0)
		data->minimap.keycode_sides = -1;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int	old_x;

	(void)y;
	if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGHT || y < 0)
		return (0);
	old_x = data->store_x;
	if (x < old_x)
		key_press(123, data);
	else if (x > old_x)
		key_press(124, data);
	data->minimap.mouse_move = 1;
	data->store_x = x;
	return (0);
}

int	main(void)
{
	t_data	data;

	ft_map(data.map, map);
	ft_init(&data);
	raycast(&data);
	mlx_hook(data.mlx.win_ptr, 17, 0, close_win, &data);
	mlx_hook(data.mlx.win_ptr, 2, 0, key_press, &data);
	mlx_hook(data.mlx.win_ptr, 3, 0, key_release, &data);
	mlx_hook(data.mlx.win_ptr, 6, 0, mouse_move, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, &raycast, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
