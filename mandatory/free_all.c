/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:35:57 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 14:34:10 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*my_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (c == '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}

void	my_free_map_components(t_game *game)
{
	unsigned int	hght_tmp;

	hght_tmp = -1;
	while (++hght_tmp < game->map_hght)
	{
		if (game->map_components[hght_tmp])
			free(game->map_components[hght_tmp]);
	}
	if (game->map_components)
		free (game->map_components);
}

int	my_free_map_components2(t_game *game)
{
	unsigned int	hght_tmp;

	hght_tmp = -1;
	while (++hght_tmp < game->map_hght)
	{
		if (game->map_components[hght_tmp])
			free(game->map_components[hght_tmp]);
	}
	if (game->map_components)
		free (game->map_components);
	ft_putstr_fd("Error\nCannot allocate mamory\n", 2);
	return (1);
}

int	free_map(t_data *data, unsigned int height)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		if (data->map_test[i])
			free(data->map_test[i]);
		i++;
	}
	if (data->map_test)
		free(data->map_test);
	return (1);
}
