/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:00:01 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/19 18:52:53 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_remove_tetri(t_res *res, t_tetri *tab)
{
	int i;
	int j;
	int hash;

	i = 0;
	hash = 0;
	while (i < res->size && hash < 4)
	{
		j = 0;
		while (j < res->size && hash < 4)
		{
			if (res->smap[i][j] == 65 + tab->order)
			{
				res->smap[i][j] = '.';
				hash++;
			}
			j++;
		}
		i++;
	}
	tab->put = 0;
}
