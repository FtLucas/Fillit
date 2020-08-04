/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:50:22 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/14 11:52:26 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;

	res = (unsigned char *)s;
	while (n)
	{
		if (*res == (unsigned char)c)
			return (res);
		res++;
		n--;
	}
	return (NULL);
}
