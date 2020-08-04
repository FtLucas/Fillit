/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:53:06 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/26 14:35:09 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *nee)
{
	size_t i;
	size_t j;

	i = 0;
	if (nee[i] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i] == nee[j] && nee[j] != '\0')
		{
			i++;
			j++;
		}
		if (nee[j] == '\0')
			return ((char *)hay + i - j);
		j >= 1 ? i = i - j : i;
		i++;
	}
	return (NULL);
}
