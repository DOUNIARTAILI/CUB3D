/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:57:16 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/11 08:13:55 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	pars_textures_1(char **line, int result, int fd, t_game **game)
{
	free(*line);
	if (result)
		return (1);
	*line = get_next_line(fd);
	(*game)->map_h_tmp++;
	return (0);
}

static int	pars_textures(t_game *game, int fd, char **line, t_data *data)
{
	int		result;

	result = 0;
	*line = get_next_line(fd);
	while ((*line) != NULL)
	{
		if (**line == 'N' || **line == 'S' || **line == 'E' || **line == 'W')
			result = pars_textures1(*line, data);
		else if (**line == 'C' || **line == 'F')
			result = pars_textures2(game, data, *line, **line);
		else if (check_line(*line))
		{
			free(*line);
			my_return_mistake(19);
			exit(1);
		}
		else if (contain_one(*line))
			return (0);
		if (pars_textures_1(line, result, fd, &game))
			return (1);
	}
	if ((*line) == NULL)
		return (my_return_mistake(9));
	return (0);
}

static int	is_settings_valid(t_game *game, t_data *data)
{
	if (game->floor_color > 16777215 || game->ceil_color > 16777215)
		return (my_return_mistake(13));
	if (data->cnv_img1 == NULL)
		return (my_return_mistake(14));
	if (data->cnv_img2 == NULL)
		return (my_return_mistake(14));
	if (data->cnv_img3 == NULL)
		return (my_return_mistake(14));
	if (data->cnv_img4 == NULL)
		return (my_return_mistake(14));
	return (0);
}

static unsigned int	my_calc_lines(t_game *game, const char *map)
{
	unsigned int	result;
	int				fd;
	char			*tmp;

	result = 1;
	fd = open (map, O_RDONLY);
	if (fd == -1)
		return (my_return_mistake(3));
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		result++;
		free(tmp);
		tmp = get_next_line(fd);
		if (result > game->map_h_tmp && tmp != NULL)
			game->map_hght++;
	}
	close (fd);
	return (result);
}

int	pars_map(t_game *game, const char *map, int fd, t_data *data)
{
	char			*line;
	unsigned int	i;

	if ((pars_textures(game, fd, &line, data))
		|| (is_settings_valid(game, data)))
		return (1);
	if (my_calc_lines(game, map) < 3)
		return (1);
	game->map_components = (char **)malloc(sizeof (char *) * game->map_hght);
	if (!game->map_components)
		return (my_return_mistake(5));
	i = -1;
	while (++i < (game->map_hght))
	{
		game->map_components[i] = malloc(1000);
		if (game->map_components[i] == NULL)
			return (my_free_map_components2(game));
		ft_memcpy(game->map_components[i], line, ft_strlen(line));
		if (game->map_components[i][ft_strlen(line) - 1] == '\n')
			game->map_components[i][ft_strlen(line) - 1] = '\0';
		free(line);
		line = get_next_line(fd);
	}
	return (my_check_map(game, data));
}
