/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:42:03 by drtaili           #+#    #+#             */
/*   Updated: 2023/08/14 05:16:08 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	sidedist_step(t_data *data, t_raycast *rc, t_dda *dda_)
{
	if (rc->ray.x < 0)
	{
		dda_->step_x = -1;
		dda_->side_dist.x = (data->pos.x - dda_->map_x) * dda_->delta_dist.x;
	}
	else
	{
		dda_->step_x = 1;
		dda_->side_dist.x = (dda_->map_x + 1.0 - data->pos.x)
			* dda_->delta_dist.x;
	}
	if (rc->ray.y < 0)
	{
		dda_->step_y = -1;
		dda_->side_dist.y = (data->pos.y - dda_->map_y) * dda_->delta_dist.y;
	}
	else
	{
		dda_->step_y = 1;
		dda_->side_dist.y = (dda_->map_y + 1.0 - data->pos.y)
			* dda_->delta_dist.y;
	}
}

static void	prepare_dda(t_data *data, t_raycast *rc, t_dda *dda_)
{
	dda_->map_x = (int)data->pos.x;
	dda_->map_y = (int)data->pos.y;
	dda_->delta_dist.x = 1e30;
	if (dda_->delta_dist.x != 0)
		dda_->delta_dist.x = fabs(1.0 / rc->ray.x);
	dda_->delta_dist.y = 1e30;
	if (dda_->delta_dist.y != 0)
		dda_->delta_dist.y = fabs(1.0 / rc->ray.y);
	sidedist_step(data, rc, dda_);
}

void	dda(t_data *data, t_raycast *rc, t_dda *dda_)
{
	prepare_dda(data, rc, dda_);
	dda_->hit = 0;
	while (!dda_->hit)
	{
		if (dda_->side_dist.x < dda_->side_dist.y)
		{
			dda_->side_dist.x += dda_->delta_dist.x;
			dda_->map_x += dda_->step_x;
			dda_->side = X;
		}
		else
		{
			dda_->side_dist.y += dda_->delta_dist.y;
			dda_->map_y += dda_->step_y;
			dda_->side = Y;
		}
		dda_->hit = (data->map[dda_->map_x][dda_->map_y] > 0);
	}
	if (dda_->side == X)
		dda_->perp_wall_dist = (dda_->side_dist.x - dda_->delta_dist.x);
	else
		dda_->perp_wall_dist = (dda_->side_dist.y - dda_->delta_dist.y);
}

int	close_win(t_data *data)
{
	(void)data;
	exit(0);
}
