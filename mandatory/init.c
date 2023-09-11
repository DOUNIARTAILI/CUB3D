/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:55:51 by drtaili           #+#    #+#             */
/*   Updated: 2023/09/10 19:05:02 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	map_into_int_1(t_data *data, t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < game->map_hght)
	{
		j = 0;
		while (game->map_components[i][j])
		{
			if (game->map_components[i][j] == '0'
				|| game->map_components[i][j] == '1')
				data->map_test[i][j] = game->map_components[i][j] - '0';
			else
				data->map_test[i][j] = -1;
			j++;
		}
		i++;
	}
}

int	map_into_int(t_game *game, t_data **data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	(*data)->map_test = malloc(sizeof(int *) * game->map_hght);
	if (!(*data)->map_test)
		return (1);
	while (i < game->map_hght)
	{
		(*data)->map_test[i] = malloc(sizeof(int) * game->map_lnght);
		if (!(*data)->map_test[i])
			return (free_map((*data), game->map_hght));
		i++;
	}
	map_into_int_1((*data), game);
	return (0);
}

int	ft_init(t_data *data, t_game *game)
{
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!data->mlx.win_ptr)
		return (my_free_map_components(game), 1);
	data->img = mlx_new_image(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		return (my_free_map_components(game), 1);
	data->addr = (int *)mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length,
			&data->endian);
	data->minimap.map_width = game->map_lnght;
	data->minimap.map_height = game->map_hght;
	if (map_into_int(game, &data))
		return (my_free_map_components(game), 1);
	my_free_map_components(game);
	data->store_x = WIN_WIDTH / 2;
	data->minimap.keycode_move = -1;
	data->minimap.keycode_rotate = -1;
	data->minimap.keycode_sides = -1;
	data->minimap.mouse_move = 0;
	data->minimap.turn_direction = -1;
	data->minimap.minimap_tile = 10;
	return (0);
}
