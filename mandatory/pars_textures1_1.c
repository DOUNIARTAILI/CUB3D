/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures1_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:48:36 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/10 18:37:25 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_textures2(int sign, t_data *data)
{
	if (sign == 0)
	{
		if (data->cnv_img1 == NULL)
			return (0);
	}
	else if (sign == 1)
	{
		if (data->cnv_img2 == NULL)
			return (0);
	}
	else if (sign == 2)
	{
		if (data->cnv_img3 == NULL)
			return (0);
	}
	else if (sign == 3)
	{
		if (data->cnv_img4 == NULL)
			return (0);
	}
	return (1);
}

void	get_textures_add(int sign, t_data *data)
{
	if (sign == 0)
	{
		data->cnv_addr1 = (int *)mlx_get_data_addr(data->cnv_img1, \
				&data->cnv_bpp1, &data->cnv_ll1, &data->cnv_en1);
	}
	else if (sign == 1)
	{
		data->cnv_addr2 = (int *)mlx_get_data_addr(data->cnv_img2, \
				&data->cnv_bpp2, &data->cnv_ll2, &data->cnv_en2);
	}
	else if (sign == 2)
	{
		data->cnv_addr3 = (int *)mlx_get_data_addr(data->cnv_img3, \
				&data->cnv_bpp3, &data->cnv_ll3, &data->cnv_en3);
	}
	else if (sign == 3)
	{
		data->cnv_addr4 = (int *)mlx_get_data_addr(data->cnv_img4, \
				&data->cnv_bpp4, &data->cnv_ll4, &data->cnv_en4);
	}
}

int	check_textures1(int sign, t_data *data)
{
	if (sign == 0)
	{
		if (data->cnv_img1 != NULL)
			return (1);
	}
	else if (sign == 1)
	{
		if (data->cnv_img2 != NULL)
			return (2);
	}
	else if (sign == 2)
	{
		if (data->cnv_img3 != NULL)
			return (3);
	}
	else if (sign == 3)
	{
		if (data->cnv_img4 != NULL)
			return (4);
	}
	return (0);
}
