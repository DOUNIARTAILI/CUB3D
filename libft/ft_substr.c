/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:15:09 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:31:16 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*outp;
	size_t	len_s;
	size_t	len_outp;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_strdup(""));
	if ((len_s - start) > len)
		len_outp = len;
	else
		len_outp = (len_s - start);
	outp = (char *)malloc(sizeof(char) * len_outp + 1);
	if (outp == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		outp[i] = s[start + i];
		i++;
	}
	outp[i] = '\0';
	return (outp);
}
