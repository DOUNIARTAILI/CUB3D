/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:14:21 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:29:47 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*outp;
	unsigned long	i;

	i = 0;
	while (s1[i])
		i++;
	outp = malloc((i + 1) * sizeof(char));
	if (outp == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		outp[i] = s1[i];
		i++;
	}
	outp[i] = '\0';
	return (outp);
}
