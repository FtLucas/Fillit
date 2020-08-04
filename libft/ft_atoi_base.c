/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:16:55 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/26 14:06:18 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_boucle(const char *str, size_t i, int base)
{
	int		res;
	int		j;
	char	*listebases;

	res = 0;
	j = 0;
	listebases = "0123456789abcdef";
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f'))
	{
		res = res * base;
		if (str[i] >= '0' && str[i] <= '9')
			res = res + str[i] - 48;
		else
		{
			while (listebases[j] != str[i])
				j++;
			res = res + j;
			j = 0;
		}
		i++;
	}
	return (res);
}

int				ft_atoi_base(const char *str, int base)
{
	size_t	i;
	int		res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		str[i] == '-' ? neg = -1 : neg;
		i++;
	}
	res = ft_atoi_boucle(str, i, base);
	return (res * neg);
}
