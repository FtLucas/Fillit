/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:48:43 by dacuvill          #+#    #+#             */
/*   Updated: 2018/12/11 12:10:49 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strchri(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			return (i);
		i++;
		s++;
	}
	return (i);
}
