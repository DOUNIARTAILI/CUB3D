/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:11:20 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/10 19:56:30 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	pars_textures2_1(char **line)
{
	unsigned long long	i;
	char				str[4];

	while (**line == ' ')
		(*line)++;
	i = 0;
	while ((**line) && (**line) != ',' && (**line) != ' ')
	{
		if (ft_isdigit(**line))
			str[i] = **line;
		else
			break ;
		(*line)++;
		i++;
	}
	while (**line && **line == ' ')
		(*line)++;
	if (**line != ',' || i > 3)
		return (-1);
	str[i] = '\0';
	i = ft_atoi(str);
	if (i > 255)
		return (-1);
	(*line)++;
	return (i);
}

static int	pars_textures2_2(char **line)
{
	unsigned long long	i;
	char				str[4];

	while (**line == ' ')
		(*line)++;
	i = 0;
	while ((**line) && (**line) != ' ')
	{
		if (ft_isdigit(**line))
			str[i] = **line;
		else
			break ;
		(*line)++;
		i++;
	}
	while (**line == ' ')
		(*line)++;
	if (**line != '\0' && **line != '\n')
		return (-1);
	str[i] = '\0';
	i = ft_atoi(str);
	if (i > 255)
		return (-1);
	(*line)++;
	return (i);
}

static void	pars_textures2_3(t_game *game, t_data *data, char c)
{
	if (c == 'C')
	{
		game->ceil_color = (game->rgb.r << 16) | (game->rgb.g << 8) | \
		game->rgb.b;
		data->ceil_color = game->ceil_color;
	}
	else
	{
		game->floor_color = (game->rgb.r << 16) | (game->rgb.g << 8) | \
		game->rgb.b;
		data->floor_color = game->floor_color;
	}
}

int	pars_textures2(t_game *game, t_data *data, char *line, char c)
{
	int			res;

	if ((c == 'C' && game->ceil_color != 100000000) || \
	(c == 'F' && game->floor_color != 100000000))
		return (my_return_mistake(7));
	line++;
	if (*line != ' ')
		return (my_return_mistake(8));
	res = pars_textures2_1(&line);
	if (res < 0)
		return (my_return_mistake(8));
	game->rgb.r = (unsigned)res;
	res = pars_textures2_1(&line);
	if (res < 0)
		return (my_return_mistake(8));
	game->rgb.g = (unsigned)res;
	res = pars_textures2_2(&line);
	if (res < 0)
		return (my_return_mistake(8));
	game->rgb.b = (unsigned)res;
	pars_textures2_3(game, data, c);
	return (0);
}
