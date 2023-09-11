/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 07:35:50 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 15:39:27 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	my_check_border(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < game->map_hght)
	{
		j = 0;
		while (game->map_components[i][j])
		{
			if (ft_strchr("0NSEW", game->map_components[i][j]))
			{
				if ((i == 0) || (i == game->map_hght - 1) || \
				(j == 0) || (j == ft_strlen(game->map_components[i]) - 1))
					return (my_return_mistake(16));
				if (!my_strchr("10NSEW", (game->map_components[i - 1][j]))
					|| !my_strchr("10NSEW", (game->map_components[i + 1][j]))
					|| !my_strchr("10NSEW", (game->map_components[i][j - 1]))
					|| !my_strchr("10NSEW", (game->map_components[i][j + 1])))
					return (my_return_mistake(16));
			}
			j++;
		}
	}
	return (0);
}

static void	my_fill_heroe_position_1(t_data *data, char *direction)
{
	if (direction[0] == 'S')
	{
		data->dir.x = 1;
		data->dir.y = 0;
		data->plane.x = 0;
		data->plane.y = -0.66;
		data->minimap.rot = 0;
	}
	if (direction[0] == 'E')
	{
		data->dir.x = 0;
		data->dir.y = 1;
		data->plane.x = 0.66;
		data->plane.y = 0;
		data->minimap.rot = 90;
	}
	if (direction[0] == 'W')
	{
		data->dir.x = 0;
		data->dir.y = -1;
		data->plane.x = -0.66;
		data->plane.y = 0;
		data->minimap.rot = 270;
	}
}

static void	my_fill_heroe_position(t_game *game, int y, int x, t_data *data)
{
	char	*directions;
	char	*direction;

	directions = "ESWN";
	data->pos.x = y + 0.25;
	data->pos.y = x + 0.25;
	direction = ft_strchr(directions, game->map_components[y][x]);
	game->map_components[y][x] = '0';
	if (direction[0] == 'N')
	{
		data->dir.x = -1;
		data->dir.y = 0;
		data->plane.x = 0;
		data->plane.y = 0.66;
		data->minimap.rot = 180;
	}
	my_fill_heroe_position_1(data, direction);
}

static int	my_check_chars_and_heroes(t_game *game, t_data *data)
{
	unsigned int	i;
	int				j;
	int				qty_heroes;

	qty_heroes = 0;
	i = -1;
	while (++i < game->map_hght)
	{
		j = -1;
		while (game->map_components[i][++j] != '\0')
		{
			if (!ft_strchr(" 01NSEW", game->map_components[i][j]))
				return (my_return_mistake(4));
			if (ft_strchr("NSEW", game->map_components[i][j]))
			{
				if (qty_heroes > 0)
					return (my_return_mistake(15));
				qty_heroes = 1;
				my_fill_heroe_position(game, i, j, data);
			}
		}
	}
	return (0);
}

int	my_check_map(t_game *game, t_data *data)
{
	unsigned int	i;
	unsigned int	j;

	game->map_lnght = my_strlen(game->map_components[0]);
	i = -1;
	while (++i < game->map_hght)
	{
		if (game->map_lnght < (unsigned int)my_strlen(game->map_components[i]))
			game->map_lnght = (unsigned int)my_strlen(game->map_components[i]);
	}
	if (check_if_player(game) || my_check_chars_and_heroes(game, data)
		|| my_check_border(game) || check_valid_lines(game))
	{
		my_free_map_components(game);
		return (1);
	}
	i = -1;
	while (++i < game->map_hght)
	{
		j = game->map_lnght;
		game->map_components[i][j] = '\0';
		while (j > 0 && game->map_components[i][--j] != '1')
			game->map_components[i][j] = ' ';
	}
	return (0);
}
