/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:35:30 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/10 19:40:54 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_back_and_forth(t_data *data, int keycode)
{
	if (keycode == 13)
	{
		if (data->map_test[(int)(data->pos.x + data->dir.x
				* MOVESPEED)][(int)data->pos.y] == 0)
			data->pos.x += data->dir.x * MOVESPEED;
		if (data->map_test[(int)data->pos.x][(int)(data->pos.y
			+ data->dir.y * MOVESPEED)] == 0)
			data->pos.y += data->dir.y * MOVESPEED;
	}
	else if (keycode == 1)
	{
		if (data->map_test[(int)(data->pos.x - data->dir.x
				* MOVESPEED)][(int)data->pos.y] == 0)
			data->pos.x -= data->dir.x * MOVESPEED;
		if (data->map_test[(int)data->pos.x][(int)(data->pos.y
			- data->dir.y * MOVESPEED)] == 0)
			data->pos.y -= data->dir.y * MOVESPEED;
	}
}

void	move_sideways(t_data *data, int keycode)
{
	if (keycode == 2)
	{
		if (data->map_test[(int)(data->pos.x + data->plane.x
				* MOVESPEED)][(int)data->pos.y] == 0)
			data->pos.x += data->plane.x * MOVESPEED;
		if (data->map_test[(int)data->pos.x][(int)(data->pos.y
			+ data->plane.y * MOVESPEED)] == 0)
			data->pos.y += data->plane.y * MOVESPEED;
	}
	else if (keycode == 0)
	{
		if (data->map_test[(int)(data->pos.x - data->plane.x
				* MOVESPEED)][(int)data->pos.y] == 0)
			data->pos.x -= data->plane.x * MOVESPEED;
		if (data->map_test[(int)data->pos.x][(int)(data->pos.y
			- data->plane.y * MOVESPEED)] == 0)
			data->pos.y -= data->plane.y * MOVESPEED;
	}
}

int	my_return_mistake1(int i)
{
	if (i == 11)
		ft_putstr_fd("Error\nTexture is duplicated\n", 2);
	else if (i == 12)
		ft_putstr_fd("Error\nCannot load textures\nUnknown file's type\
		\nUse .xpm files as textures\n", 2);
	else if (i == 13)
		ft_putstr_fd("Error\nFloor and celling weren't set\nRight format:\
		\nF 220,100,0 and C 225,30,0 where R,G,B - colors in range [0,255]\n", 2);
	else if (i == 14)
		ft_putstr_fd("Error\nTextures weren't set\nRight format:\
		\nNO (SO, WE, EA) ./path_to_the_texture\
		\nUse .xpm files as textures\n", 2);
	else if (i == 15)
		ft_putstr_fd("Error\nStart position is duplicated\n", 2);
	else if (i == 16)
		ft_putstr_fd("Error\nThe map must be closed/surrounded by walls\n", 2);
	else if (i == 17)
		ft_putstr_fd("Error\nThe map must be contains a player\n", 2);
	else if (i == 18)
		ft_putstr_fd("Error\nCreating Window or Image\n", 2);
	else if (i == 19)
		ft_putstr_fd("Error\nmap have unknown characters\n", 2);
	return (1);
}

int	my_return_mistake(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nUse it: ./cub3d MAP_NAME.cub\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nThe extension of map must be .cub\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nCannot read the map\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nMap is not valid\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error\nCannot allocate mamory\n", 2);
	else if (i == 6)
		ft_putstr_fd("Error\nCannot load textures\n", 2);
	else if (i == 7)
		ft_putstr_fd("Error\nFloor or ceilling color is duplicated\n", 2);
	else if (i == 8)
		ft_putstr_fd("Error\nWrong floor or celling format\nRight format: \
		\nF 220,100,0 and C 225,30,0 where R,G,B - colors in range [0,255]\n", 2);
	else if (i == 9)
		ft_putstr_fd("Error\nMap is not exist\n", 2);
	else if (i == 10)
		ft_putstr_fd("Error\nWronr textures format\nRight format:\
		\nNO (SO, WE, EA) ./path_to_the_texture\n", 2);
	return (my_return_mistake1(i));
}
