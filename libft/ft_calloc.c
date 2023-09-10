/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:11:28 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:25:42 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*outp;
	unsigned long	i;
	size_t			mem;

	mem = count * size;
	if (count && size != (mem / count))
	{
		errno = ENOMEM;
		return (NULL);
	}
	outp = malloc(mem);
	if (outp == NULL)
		return (NULL);
	i = 0;
	while (i < mem)
	{
		((unsigned char *)outp)[i] = 0;
		i++;
	}
	return (outp);
}
