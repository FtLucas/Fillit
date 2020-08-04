/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:53:48 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/19 15:56:51 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_delmap(t_res **res)
{
	int i;

	i = 0;
	if ((*res)->smap != NULL)
	{
		while (i < (*res)->size)
		{
			ft_strdel(&(*res)->smap[i]);
			i++;
		}
		free((*res)->smap);
	}
	if (res != NULL && *res != NULL)
		free(*res);
}
