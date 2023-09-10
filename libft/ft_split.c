/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:13:54 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/09/09 11:29:22 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_qty_of_words(char const *s, char c)
{
	unsigned long	i;
	int				outp;

	i = 0;
	outp = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			outp++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (outp);
}

static char	**my_free_array(char **outp)
{
	unsigned int	i;

	i = 0;
	while (outp[i])
	{
		free(outp[i]);
		i++;
	}
	free(outp);
	return (NULL);
}

static char	*my_fill_array(char const *str, char c)
{
	char			*outp;
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	outp = malloc(sizeof(char) * (i + 1));
	if (!outp)
	{
		my_free_array(&outp);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != c)
	{
		outp[i] = str[i];
		i++;
	}
	outp[i] = '\0';
	return (outp);
}

static char	**my_split(char **outp, char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			outp[i] = my_fill_array(s, c);
			if (!outp[i])
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	outp[i] = NULL;
	return (outp);
}

char	**ft_split(char const *s, char c)
{
	int				qty_words;
	char			**outp;

	if (!s)
		return (NULL);
	qty_words = my_qty_of_words(s, c);
	outp = (char **)malloc((qty_words + 1) * sizeof(char *));
	if (!outp)
		return (NULL);
	return (my_split(outp, s, c));
}
