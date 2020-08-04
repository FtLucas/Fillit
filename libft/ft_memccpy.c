/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:38:40 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/24 21:11:27 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	while (i < n && *(unsigned char *)src != (unsigned char)c)
	{
		uc = *(unsigned char *)src;
		*(unsigned char *)dst = uc;
		i++;
		dst++;
		src++;
	}
	if (i < n && *(unsigned char *)src == (unsigned char)c)
	{
		uc = *(unsigned char *)src;
		*(unsigned char *)dst = uc;
		return (dst + 1);
	}
	return (NULL);
}
