/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:55:08 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/25 04:15:16 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	int			ok;
	size_t		s;

	i = 0;
	j = 0;
	ok = 1;
	s = 0;
	while (s1[i] != '\0' && ok == 1)
	{
		ok = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				s++;
				i++;
				ok = 1;
			}
			j++;
		}
		j = 0;
	}
	return (s);
}
