/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:13:37 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:28:53 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned long	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &(s[i]), 1);
			i++;
		}
		write (fd, "\n", 1);
	}
}
