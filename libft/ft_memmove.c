/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:35:28 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/26 14:38:50 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmpd;
	unsigned char	*tmps;

	i = 0;
	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	if (src < dst)
	{
		while (len > 0)
		{
			tmpd[len - 1] = tmps[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			tmpd[i] = tmps[i];
			i++;
		}
	}
	return (dst);
}
