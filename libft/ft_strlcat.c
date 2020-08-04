/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:03:15 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/24 18:46:36 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sdst;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && size > i && size != 0)
		i++;
	sdst = i;
	while (src[j] != '\0' && i < size - 1 && size != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (sdst < size && size != 0)
		dst[i] = '\0';
	return (ft_strlen(src) + sdst);
}
