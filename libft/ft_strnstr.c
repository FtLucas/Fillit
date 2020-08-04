/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:11:41 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/25 02:49:25 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (nee[i] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && len > 0)
	{
		j = 0;
		while (hay[i] == nee[j] && nee[j] != '\0' && len > 0)
		{
			i++;
			j++;
			len--;
		}
		if (nee[j] == '\0')
			return ((char *)hay + i - j);
		j >= 1 ? i = i - j : i;
		j >= 1 ? len = len + j : len;
		i++;
		len--;
	}
	return (NULL);
}
