/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:11:18 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:25:29 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_numlen(const char *s)
{
	size_t	len;

	len = 0;
	while (ft_isdigit(*s))
	{
		len++;
		s++;
	}
	return (len);
}

static int	my_if_overlong(const char *str)
{
	int		sgn;
	size_t	len;

	sgn = -1;
	if (*str == '-')
		sgn = 0;
	if (*str == '+' || *str == '-')
		str++;
	len = my_numlen(str);
	if (len > 19)
		return (sgn);
	if (sgn == -1 && len == 19 && \
		ft_strncmp(str, "9223372036854775807", 19) > 0)
		return (sgn);
	if (sgn == 0 && len == 19 && ft_strncmp(str, "9223372036854775808", 19) > 0)
		return (sgn);
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					minus;
	unsigned long long	outp;

	while (*str && (*str == '\n' || *str == '\t' || *str == '\v' || \
		*str == '\r' || *str == '\f' || *str == 32))
		str++;
	minus = my_if_overlong(str);
	if (minus != 1)
		return (minus);
	i = 0;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	outp = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		outp = outp * 10 + str[i] - '0';
		i++;
	}
	return ((int)outp * minus);
}
