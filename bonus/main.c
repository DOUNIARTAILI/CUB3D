/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:50:06 by drtaili           #+#    #+#             */
/*   Updated: 2023/09/11 11:30:20 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	key_press(int keycode, t_data *data)
{
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

static int	my_check_map_extension(const char *map)
{
	char	*tmp;

	tmp = ft_strrchr(map, '.');
	if (!tmp || ft_strcmp(tmp, ".cub"))
		return (my_return_mistake(3));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_game	game;
	int		fd;

	if (argc != 2)
		return (my_return_mistake(1));
	if (my_check_map_extension(argv[1]) == 1)
		return (my_return_mistake(2));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (my_return_mistake(3));
	parsing(argv[1], fd, &data, &game);
	if (ft_init(&data, &game))
		return (my_return_mistake(18));
	raycast(&data);
	mlx_hook(data.mlx.win_ptr, 17, 0, close_win, &data);
	mlx_hook(data.mlx.win_ptr, 2, 0, key_press, &data);
	mlx_hook(data.mlx.win_ptr, 3, 0, key_release, &data);
	mlx_hook(data.mlx.win_ptr, 6, 0, mouse_move, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, &raycast, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
