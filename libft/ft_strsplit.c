/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:04:07 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/26 22:33:23 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		*ft_strdelsplit(char ***as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return (NULL);
}

static int		ft_nbw(const char *s, char c)
{
	size_t i;
	size_t nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			nb++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (nb);
}

static int		ft_slw(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t		i;
	size_t		j;
	char		**str;

	i = 0;
	j = 0;
	if ((!(s)) || (!(str = (char **)malloc(sizeof(char *) * ft_nbw(s, c) + 1))))
		return (NULL);
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0')
		{
			if (!(str[i] = (char *)malloc(sizeof(char) * ft_slw(&s[j], c) + 1)))
				return (ft_strdelsplit(&str));
			str[i++] = ft_strsub(s, j, ft_slw(&s[j], c));
		}
		while (s[j] != '\0' && s[j] != c)
			j++;
	}
	str[i] = 0;
	return (str);
}
