/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:59:54 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/10 18:37:54 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	store_textures(int sign, t_data *data, char *line)
{
	if (sign == 0)
		data->cnv_img1 = mlx_xpm_file_to_image(data->mlx.mlx_ptr, \
				line, &data->tex_w, &data->tex_h);
	else if (sign == 1)
		data->cnv_img2 = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
				line, &data->tex_w, &data->tex_h);
	else if (sign == 2)
		data->cnv_img3 = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
				line, &data->tex_w, &data->tex_h);
	else if (sign == 3)
		data->cnv_img4 = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
				line, &data->tex_w, &data->tex_h);
	printf("tex_w = %d | tex_h = %d\n", data->tex_w, data->tex_h);
}

static int	pars_textures1_1(char *line, int sign, t_data *data)
{
	unsigned int	len;
	char			*tmp;

	tmp = line;
	len = ft_strlen(line);
	if (len < 5)
		return (my_return_mistake(12));
	tmp[len - 1] = '\0';
	if (ft_memcmp(".xpm", tmp + len - 5, 4) == 0)
		store_textures(sign, data, line);
	else
		return (my_return_mistake(12));
	if (check_textures2(sign, data) == 0)
		return (my_return_mistake(6));
	get_textures_add(sign, data);
	return (0);
}

int	pars_textures1(char *line, t_data *data)
{
	int	sign;

	if (line[0] == 'N' && line[1] == 'O')
		sign = 1;
	else if (line[0] == 'S' && line[1] == 'O')
		sign = 0;
	else if (line[0] == 'E' && line[1] == 'A')
		sign = 2;
	else if (line[0] == 'W' && line[1] == 'E')
		sign = 3;
	else
		return (my_return_mistake(10));
	if (check_textures1(sign, data))
		return (my_return_mistake(11));
	if (line[2] != ' ')
		return (my_return_mistake(10));
	line += 2;
	while (*line && *line == ' ')
		line++;
	return (pars_textures1_1(line, sign, data));
}
