/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:46:19 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/25 04:11:23 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	while (i > 0)
	{
		if (*s == c)
			return ((char *)s);
		i--;
		s--;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
