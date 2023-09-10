/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:15:00 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:30:46 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		tmp;
	char	*outp;

	i = 0;
	tmp = -1;
	outp = (char *)s;
	while (outp[i])
	{
		if (outp[i] == (char) c)
		{
			tmp = i;
		}
		i++;
	}
	if ((char) c == '\0')
		tmp = i;
	if (tmp == -1)
		return (NULL);
	else
		return (&outp[tmp]);
}
