/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:14:47 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:30:34 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*outp;
	unsigned long	len_s;

	if (!s)
		return (NULL);
	len_s = 0;
	while (s[len_s])
		len_s++;
	outp = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!outp)
		return (NULL);
	outp[len_s] = '\0';
	while (len_s > 0)
	{
		outp[len_s - 1] = f(len_s - 1, s[len_s - 1]);
		len_s--;
	}
	return (outp);
}
