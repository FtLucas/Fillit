/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:48:01 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/19 19:08:09 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"
#include "./libft/libft.h"
#include <stdlib.h>

static void		ft_free_tab(t_tetri *tab)
{
	t_tetri	*tmp;

	tmp = NULL;
	if (tab->last != 1)
	{
		tmp = tab + 1;
		while (tab->last != 0)
		{
			tmp = tab + 1;
			free(tab);
			tab = tmp;
		}
	}
	free(tab);
}

static void		ft_free_res(t_res *res)
{
	res->size++;
	while (0 <= --res->size)
		ft_strdel(&res->smap[res->size]);
	free(res->smap);
}

static int		ft_fill_map(t_res *res, t_tetri *tab, int i, int j)
{
	while (i < res->size)
	{
		while (j < res->size)
		{
			if (ft_check_and_fill(res, tab, i, j) == 0)
			{
				if (tab->put == 1 && tab->last == 1)
					return (1);
				if (ft_fill_map(res, tab + 1, 0, 0) != 1)
					ft_remove_tetri(res, tab);
				else
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static t_res	*ft_resize_map(t_res *res, int size)
{
	int i;
	int j;

	i = 0;
	if (res->smap != NULL)
		ft_free_res(res);
	res->size = size;
	if (!(res->smap = malloc(sizeof(char *) * size + 1)))
		return (ft_error());
	res->smap[size] = 0;
	while (size > 0)
	{
		j = res->size;
		if (!(res->smap[i] = malloc(sizeof(char) * res->size + 1)))
			return (ft_error());
		res->smap[i][res->size] = '\0';
		while (--j >= 0)
			res->smap[i][j] = '.';
		i++;
		size--;
	}
	return (res);
}

void			*ft_solve(t_tetri *tab, int min_size)
{
	int		i;
	t_res	*res;

	res = NULL;
	if (!(res = malloc(sizeof(t_res))))
		return (ft_error());
	res->smap = NULL;
	if (!(res = ft_resize_map(res, min_size)))
		return (ft_error());
	while (ft_fill_map(res, tab, 0, 0) != 1)
	{
		i = -1;
		if (!(ft_resize_map(res, res->size + 1)))
			return (ft_error());
		while (tab[++i].last != 1)
			tab[i].put = 0;
		tab[i].put = 0;
	}
	ft_free_tab(tab);
	return ((t_res *)res);
}
