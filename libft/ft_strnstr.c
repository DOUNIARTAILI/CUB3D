/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:14:56 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:30:41 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*outp;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i < (int)len && haystack[i])
	{
		if (haystack[i] == needle [0])
		{
			outp = &((char *)haystack)[i];
			j = 0;
			while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0' && (i + j) <= (int)len)
				return (outp);
		}
		i++;
	}
	return (NULL);
}
