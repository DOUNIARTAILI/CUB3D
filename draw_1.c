/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:31:51 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 14:33:19 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_line(t_data *data, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		data->addr[y * WIN_WIDTH + x] = data->ceil_color;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		data->addr[y * WIN_WIDTH + x] = data->floor_color;
		y++;
	}
}

int	get_color(t_data *data, t_dda *dda_, t_raycast *rc)
{
	int	color;

	color = 0;
	if (dda_->side == 0 && rc->ray.x > 0)
		color = *(data->cnv_addr1 + (data->tex_h * data->texy + data->texx));
	else if (dda_->side == 0 && rc->ray.x < 0)
		color = *(data->cnv_addr2 + (data->tex_h * data->texy + data->texx));
	else if (dda_->side == 1 && rc->ray.y > 0)
		color = *(data->cnv_addr3 + (data->tex_h * data->texy + data->texx));
	else if (dda_->side == 1 && rc->ray.y < 0)
		color = *(data->cnv_addr4 + (data->tex_h * data->texy + data->texx));
	return (color);
}
