/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:14:35 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:30:24 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_src = 0;
	while (src[len_src])
		len_src++;
	len_dst = 0;
	while (dst[len_dst] && len_dst < dstsize)
		len_dst++;
	i = len_dst;
	while (src[len_dst - i] && len_dst + 1 < dstsize)
	{
		dst[len_dst] = src[len_dst - i];
		len_dst++;
	}
	if (i < dstsize)
		dst[len_dst] = '\0';
	return (i + len_src);
}
