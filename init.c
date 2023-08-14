/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drtaili <drtaili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:55:51 by drtaili           #+#    #+#             */
/*   Updated: 2023/08/14 01:55:35 by drtaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_init(t_data *data)
{
    data->mlx.mlx_ptr = mlx_init();
	data->cnv_img = mlx_xpm_file_to_image(data->mlx.mlx_ptr, "/Users/drtaili/Desktop/cub3d/xpmimg/wall2.xpm", &data->cnv_w, &data->cnv_h);
	if (data->cnv_img == NULL)
		return ;
	data->cnv_addr = (int *)mlx_get_data_addr(data->cnv_img, &data->cnv_bpp, &data->cnv_ll, &data->cnv_en);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data->img = mlx_new_image(data->mlx.mlx_ptr, WIN_WIDTH,  WIN_HEIGHT);
	data->addr = (int *)mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length,
			&data->endian);
	data->pos.x = 22;
	data->pos.y = 12;
	data->dir.x = -1;
	data->dir.y = 0;
	data->plane.x = 0;
	data->plane.y = 0.66;
	data->store_x = WIN_WIDTH / 2;
}