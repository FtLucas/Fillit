/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:27:22 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/17 14:23:47 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_add_tetri(t_res *res, t_tetri *tab, int i, int j)
{
	int k;
	int l;
	int it;

	it = 0;
	while (it < 4)
	{
		k = i + tab->t[it].y;
		l = j + tab->t[it].x;
		res->smap[k][l] = 65 + tab->order;
		it++;
	}
	tab->put = 1;
}

int				ft_check_and_fill(t_res *res, t_tetri *tab, int i, int j)
{
	int it;
	int k;
	int l;

	it = 0;
	k = i + tab->t[it].y;
	l = j + tab->t[it].x;
	while (k < res->size && l < res->size && res->smap[k][l] == '.' && it < 4)
	{
		it++;
		k = i + tab->t[it].y;
		l = j + tab->t[it].x;
	}
	if (it == 4)
	{
		ft_add_tetri(res, tab, i, j);
		return (0);
	}
	return (1);
}
