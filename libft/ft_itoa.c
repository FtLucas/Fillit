/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:42:22 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/25 03:04:40 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_itoa_boucle(char *str, size_t k, long int nb, int size)
{
	int	j;
	int i;

	j = 0;
	if (k == 1)
		str[0] = '-';
	str[size] = '\0';
	i = 1;
	size > 1 ? i = ft_power(10, size - 1) : i;
	while (size > 0)
	{
		j = j * 10;
		str[k] = ((nb / i) - j) + 48;
		j = j + (str[k] - 48);
		if (i > 10)
			i = i / 10;
		else
			i = 1;
		k++;
		size--;
	}
	str[k] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int			size;
	long int	i;
	long int	nb;
	size_t		neg;
	char		*str;

	size = 0;
	neg = 0;
	nb = n;
	if (nb < 0)
	{
		neg = 1;
		nb = nb * -1;
	}
	i = nb;
	if (i == 0)
		size = 1;
	while (i > 0)
	{
		i = i / 10;
		size++;
	}
	if (!(str = (char *)malloc(sizeof(char) * size + neg + 1)))
		return (NULL);
	return (ft_itoa_boucle(str, neg, nb, size));
}
