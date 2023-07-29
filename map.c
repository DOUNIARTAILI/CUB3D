/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:43:54 by drtaili           #+#    #+#             */
/*   Updated: 2023/07/29 21:46:15 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_map(int dst[map_width][map_height], int src[map_width][map_height])
{
	int	i;
	int	j;

	i = 0;
	while (i < map_width)
	{
		j = 0;
		while (j < map_height)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}