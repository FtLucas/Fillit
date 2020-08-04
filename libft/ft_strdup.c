/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:42:24 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/25 03:53:31 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*sdup;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(sdup = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sdup[i] = s1[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}
