/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:08:42 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/26 14:36:02 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*strim;

	i = 0;
	k = 0;
	if (!(s))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s);
	while (--j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		k++;
	j = 0;
	i == ft_strlen(s) - 1 ? i = 0 : i;
	k == ft_strlen(s) - 1 ? k = 0 : k;
	if (!(strim = (char *)malloc(sizeof(char) * (ft_strlen(s) - (i + k)) + 1)))
		return (NULL);
	while (i < ft_strlen(s) - k)
		strim[j++] = s[i++];
	strim[j] = '\0';
	return (strim);
}
