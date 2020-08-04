/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:57:04 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/25 11:20:56 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	i;
	size_t	j;

	i = 0;
	if ((!(s1)) || (!(s2)))
		return (NULL);
	j = ft_strlen(s2);
	if (!(sj = (char *)malloc(sizeof(char) * (ft_strlen(s1) + j) + 1)))
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
		sj[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
	{
		sj[i] = s2[j];
		i++;
		j++;
	}
	sj[i] = '\0';
	return (sj);
}
