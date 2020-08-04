/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:06:23 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/26 14:39:07 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	while (i < n)
	{
		uc = *(unsigned char *)src;
		*(unsigned char *)dest = uc;
		i++;
		dest++;
		src++;
	}
	return (dest - n);
}
