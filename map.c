/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:43:54 by drtaili           #+#    #+#             */
/*   Updated: 2023/08/14 04:30:28 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_map(int dst[MAP_WIDTH][MAP_HEIGHT], int src[MAP_WIDTH][MAP_HEIGHT])
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_WIDTH)
	{
		j = 0;
		while (j < MAP_HEIGHT)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}
