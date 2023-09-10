/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:52:58 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 14:55:03 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	init_game(t_game *game, t_data *data)
{
	game->ceil_color = 100000000;
	game->floor_color = 100000000;
	game->map_hght = 0;
	game->map_h_tmp = 0;
	data->cnv_img1 = NULL;
	data->cnv_img2 = NULL;
	data->cnv_img3 = NULL;
	data->cnv_img4 = NULL;
}

void	parsing(const char *map, int fd, t_data *data, t_game *game)
{
	data->mlx.mlx_ptr = mlx_init();
	if (data->mlx.mlx_ptr == NULL)
	{
		ft_putstr_fd("Error\nInitilising MLX Went Wrong\n", 2);
		exit (0);
	}
	init_game(game, data);
	if (pars_map(game, map, fd, data))
		exit (1);
}
