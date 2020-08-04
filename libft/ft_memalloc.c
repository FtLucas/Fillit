/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:29:14 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/22 15:39:02 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*m;

	i = 0;
	if (!(m = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		*m = 0;
		m++;
		i++;
	}
	return (m - size);
}
