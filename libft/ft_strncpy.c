/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:52:02 by dacuvill          #+#    #+#             */
/*   Updated: 2018/12/12 13:46:07 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (*src != '\0' && len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
		i++;
	}
	while (*src == '\0' && len != 0)
	{
		*dst = '\0';
		dst++;
		i++;
		len--;
	}
	return (dst - i);
}
