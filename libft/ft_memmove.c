/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:13:24 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:28:38 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* чтоб не перезаписать (не потерять) источник. */
/* Если цель правее источника, то надо справа налево копировать, */
/* чтобы не перезаписать (не потерять) источник. */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (src < dst)
	{
		while (len--)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		i = 0;
		if (!len || dst == src)
			return (dst);
		while (i < (unsigned int) len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
