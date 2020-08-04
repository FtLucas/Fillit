/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:18:43 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/19 15:57:09 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"
#include <stdlib.h>

static int			ft_calc_min_tab(int nb_tetri)
{
	int size_min;
	int nb_diez;

	size_min = 2;
	nb_diez = nb_tetri * 4;
	if (nb_tetri == 1)
		return (size_min);
	while (size_min * size_min < nb_diez)
		size_min++;
	return (size_min);
}

static void			*ft_reduce_coords(t_tetri *tab, int nb_tetri)
{
	int i;
	int j;
	int min_x;
	int min_y;

	i = -1;
	while (++i < nb_tetri)
	{
		j = -1;
		min_x = 3;
		min_y = 3;
		while (++j < 4)
		{
			min_x = (min_x > tab[i].t[j].x ? tab[i].t[j].x : min_x);
			min_y = (min_y > tab[i].t[j].y ? tab[i].t[j].y : min_y);
		}
		j = -1;
		while (++j < 4)
		{
			tab[i].t[j].x -= min_x;
			tab[i].t[j].y -= min_y;
		}
	}
	return ((t_res *)ft_solve(tab, ft_calc_min_tab(nb_tetri)));
}

void				ft_fill_tab(t_tetri *tab, int k, t_map *map)
{
	tab[k].order = k;
	tab[k].last = (k + 1 == map->nb_tetri ? 1 : 0);
	tab[k].put = 0;
}

void				*ft_create_list(t_map *map)
{
	int		i;
	int		j;
	int		k;
	t_tetri	*tab;

	i = 0;
	k = -1;
	if (!(tab = malloc(sizeof(t_tetri) * map->nb_tetri)))
		return (ft_error_map(map));
	while (++k < map->nb_tetri)
	{
		j = 0;
		while (j < 4)
		{
			if (map->content[i] == '#')
			{
				tab[k].t[j].x = (i - k) % 20 % 5;
				tab[k].t[j].y = (i - k) % 20 / 5;
				ft_fill_tab(tab, k, map);
				j++;
			}
			i++;
		}
	}
	return ((t_res *)ft_reduce_coords(tab, map->nb_tetri));
}
