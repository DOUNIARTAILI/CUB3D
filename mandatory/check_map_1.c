/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:26:48 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 14:29:13 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != '\n'))
		i++;
	return (i);
}

int	check_if_player(t_game *game)
{
	unsigned int	i;
	int				j;

	i = -1;
	while (++i < game->map_hght)
	{
		j = -1;
		while (game->map_components[i][++j] != '\0')
		{
			if (ft_strchr("NSEW", game->map_components[i][j]))
				return (0);
		}
	}
	return (my_return_mistake(17));
}

int	all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_lines(t_game *game)
{
	unsigned int	k;
	unsigned int	i;
	int				j;

	i = 0;
	k = 0;
	j = 0;
	while (i < game->map_hght - 1)
	{
		if ((game->map_components[i][0] == '\0'
			|| all_spaces(game->map_components[i]))
			&& (game->map_components[i + 1][0] != '\0'
			|| !all_spaces(game->map_components[i + 1])))
			return (my_return_mistake(4));
		i++;
	}
	return (0);
}
